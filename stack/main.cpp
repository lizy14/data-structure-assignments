#define LOCAL_DEBUG
/*
文件名: 
描　述: 栈和队列习题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-11

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <string>

bool validateBrackets(const std::string str, const std::string brackets = "()[]{}<>"){
	std::stack<char> stack; //holds 
	for(char chr: str){
		int pos = brackets.find(chr);
		if(pos == std::string::npos)
			continue;
		if(pos % 2 == 0){
			//it's left
			stack.push(chr);
		}else{
			//it's right
			if(stack.empty())
				return false;//extra right
			if(pos == brackets.find(stack.top())+1){
				//match
				stack.pop();
			}else{
				return false;//mismatch
			}
		}
	}
	if(!stack.empty())
		return false;//extra left
	return true;
}

//checks if a string is symmetrical about `centerOfSymmetry`
//read the string from `stream`, ending with `endOfInput`
bool isSymmetrical(
	const char centerOfSymmetry, 
	std::istream& stream, 
	const char endOfInput = EOF)
{
	std::stack<char> stack;
	char chr;
	bool foundCenterOfSymmetry = false;
	while(1){
		stream >> chr;
		if(chr == endOfInput){
			return stack.empty();
		}
		if(!foundCenterOfSymmetry){
			if(chr == centerOfSymmetry){
				foundCenterOfSymmetry = true;
				continue;
			}
			stack.push(chr);
		}else{//foundCenterOfSymmetry
			if(chr == centerOfSymmetry){
				//TODO: found multiple centerOfSymmetry
				return false;
			}
			if(stack.empty())
				return false;
			if(stack.top() == chr){
				stack.pop();
				continue;
			}
			else
				return false;
		}
	}
}


//evaluate a string consists only of integers and binary operators +-*/
int priority(const char chr){
	if(chr == '+' || chr == '-')
		return 10;
	if(chr == '*' || chr == '/')
		return 20;
	if(chr == '#')
		return 1;
	return 0;
}
class Item{
public:
	enum Type{EMTPY, OPERATOR, OPERAND} type;
	union{
		char chr;
		double dbl;
	};
public:
	Item(char c):chr(c),type(OPERATOR){}
	Item(double d):dbl(d),type(OPERAND){}
	operator double(){
		if(type!=OPERAND)
			throw "Item type error";
		return dbl;
	}
	operator char(){
		if(type!=OPERATOR)
			throw "Item type error";
		return chr;
	}
	void clear(){type=EMTPY;}
};
class SuffixExpression : public std::vector<Item>{
	//nothing here
};
void printExpression(const SuffixExpression suffixExpression){
	for(Item item : suffixExpression){
		if(item.type == Item::OPERAND)
			std::cout << (double)item << ' ';
		else if(item.type == Item::OPERATOR)
			std::cout << (char)item << ' ';
	}
	std::cout << '\n';
}
double evaluateExpression(SuffixExpression expression){
	
	int length = expression.size();
	if(length == 2)
		return expression[0];
	int i=0;
	while(i<length-1){//ignore the ending '#'

#ifdef LOCAL_DEBUG
		printExpression(expression);
#endif
		while(expression[i].type != Item::OPERATOR){
			i++;
		}
		//found an operator
		int positionOfOperator = i;
		double a, b;
		i--;
		while(expression[i].type != Item::OPERAND){
			i--;
		}
		a = expression[i];
		expression[i].clear();
		i--;
		while(expression[i].type != Item::OPERAND){
			i--;
		}
		b = expression[i];
		expression[i].clear();

		//now operands found
		double result;
		switch(expression[positionOfOperator]){
		case '+':
			result = b+a;
			break;
		case '-':
			result = b-a;
			break;
		case '*':
			result = b*a;
			break;
		case '/':
			result = b/a;
			break;
		default:
			throw "unknown operator";
		}

		expression[positionOfOperator] = result;
		i = positionOfOperator + 1;
	}
	return expression[length-2];
}
SuffixExpression makeSuffixExpression(std::string expression){
	expression = expression + "#";	
	double current = 0;
	double dot = 0.;
	
	std::stack<char> operators;
	operators.push('#');

	SuffixExpression suffixExpression;

	
	for(char chr : expression){
		

		if(('0'<=chr && chr<='9') || chr=='.'){
			//got a digit
			if(chr=='.'){
				if(dot)
					throw "invalid decimal point";
				dot = 1.;
			}else{
				if(dot){
					dot /= 10;
					current += dot * (chr - '0');
				}else{
					current *= 10;
					current += (chr - '0');
				}
			}
		}else{
			//got an operator

			//take care of something concerning reading digits
			suffixExpression.push_back(current);

			current = 0.;
			dot = 0.;

			//now deal with `chr`
			if(!priority(chr))
				throw "unknown operator";


			char top = operators.top();
			if(priority(chr) > priority(top)){
				operators.push(chr);
			}else{
				while(priority(top) >= priority(chr)){
					suffixExpression.push_back(top);
					operators.pop();
					if(operators.empty())
						break;
					top = operators.top();	
				}
				operators.push(chr);
			}
		}
	}
	return suffixExpression;
}

void printBool(bool b){
	std::cout << (b? "true": "false") << std::endl;
}
void problem3_17(){
	bool answer = isSymmetrical('&', std::cin, '@');
	printBool(answer);
}
void problem3_19(){
	std::string str;
	std::getline(std::cin, str);
	bool answer = validateBrackets(str, "()[]{}");
	printBool(answer);
}
void problem3_22(){
	std::string str;
#ifdef LOCAL_DEBUG
	while(1){
#endif
		std::getline(std::cin, str);
		std::cout << evaluateExpression(makeSuffixExpression(str)) << std::endl;
#ifdef LOCAL_DEBUG
	}
#endif
}

int main(){
	problem3_22();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
}

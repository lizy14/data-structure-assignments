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

//checks if a string is a palindrome
bool isPalindrome(
	std::istream& stream,
	const char endOfInput = EOF)
{
	std::stack<char> stack;
	std::queue<char> queue;
	char chr;
	while(1){
		stream >> chr;
		if(chr == endOfInput)
			break;
		stack.push(chr);
		queue.push(chr);
	}
	while(1){
		if(stack.empty() && queue.empty())
			return true;
		if(stack.empty() || queue.empty())
			return false;
		if(stack.top() != queue.front())
			return false;
		
		stack.pop();
		queue.pop();
	}
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

}
void problem3_28(){

}
void problem3_31(){
	bool answer = isPalindrome(std::cin, '@');
	printBool(answer);
}
void problem3_32(){

}
int main(){
	problem3_17();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
}
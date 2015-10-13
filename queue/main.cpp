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
void problem3_28(){

}
void problem3_31(){
	bool answer = isPalindrome(std::cin, '@');
	printBool(answer);
}
void problem3_32(){

}
int main(){
	problem3_31();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
}

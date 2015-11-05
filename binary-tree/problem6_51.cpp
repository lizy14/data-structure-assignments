#define LOCAL_DEBUG
/*
文件名: 
描　述: 二叉树习题 6.51 算术表达式的前缀表达式->自然形式 中序遍历

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-5

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#ifndef LOCAL_DEBUG
//OJ does not support C++11
#define nullptr NULL
#endif

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

typedef char TElemType; 

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree, *BiTLink;

BiTree makeTree(const string& str){
	int len = str.length();
	if(len == 0)
		return nullptr;
	
	BiTree tree = new BiTNode();
	tree->data = str[0];	
	tree->lchild = tree->rchild = nullptr;

	if(len == 1)
		return tree;

	int left = str.find('(');
	int right = str.rfind(')');
	
	int comma = string::npos;
	//we have to decide which one to choose.
	int stack=0;
	for(int i=left+1; i<right; i++){
		switch(str[i]){
		case '(':
			stack ++;
			break;
		case ')':
			stack --;
			break;
		case ',':
			if(stack == 0){
				comma = i;
				goto outside_break;
			}
			break;
		default:
			break;
		}
	}
	outside_break:
	/*
	_(___,___)
	 ^   ^   ^
	*/
	if(comma != string::npos){
		string left_ = str.substr(left+1, comma-left-1);
		tree->lchild = makeTree(left_);
		string right_ = str.substr(comma+1, right-comma-1);
		tree->rchild = makeTree(right_);
	}else{
		string left_ = str.substr(left+1, right-left-1);
		tree->lchild = makeTree(left_);
	}

	return tree;
}
void destroyTree(BiTree tree){
	if(tree == nullptr)
		return;
	destroyTree(tree->lchild);
	destroyTree(tree->rchild);
	delete tree;
}

inline bool isOp(char chr){
	return string("+-*/").find(chr)!=string::npos;
}
inline int priorityOfOp(char op){
	switch(op){
	case '+':
	case '-':
		return 5;
	case '*':
	case '/':
		return 10;
	}
	return 0;
}
inline bool higherPriority(char opA, char opB){
	return priorityOfOp(opA)>priorityOfOp(opB);
}

string printExpression(BiTree tree){
	stringstream ss;

	if(tree->lchild == nullptr || tree->rchild == nullptr){
		ss << tree->data;
		return ss.str();
	}

	//now we are at an operator

	bool lchildParentheses = isOp(tree->lchild->data) && higherPriority(tree->data,tree->lchild->data);
	bool rchildParentheses = isOp(tree->rchild->data) && higherPriority(tree->data,tree->rchild->data);;
	
	if(lchildParentheses)
		ss << "(";
	ss << printExpression(tree->lchild);
	if(lchildParentheses)
		ss << ")";
	ss << tree->data;
	if(rchildParentheses)
		ss << "(";
	ss << printExpression(tree->rchild);
	if(rchildParentheses)
		ss << ")";
	return ss.str();
}

int main(int argc, char *argv[]){
	string str;
#ifdef LOCAL_DEBUG
	str = "*(+(B,C),+(A,D))";
#else
	getline(cin, str);
#endif
	
	BiTree tree = makeTree(str);

	cout << printExpression(tree);

	destroyTree(tree);

#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

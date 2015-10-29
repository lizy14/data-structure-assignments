#define LOCAL_DEBUG
/*
文件名: 
描　述: 二叉树习题 6.45

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-29

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#ifndef LOCAL_DEBUG
//OJ does not support C++11
#define nullptr NULL
#endif

#include <iostream>
#include <string>
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
	int comma = str.find(',');
	if(comma != str.rfind(',')){
		//there are more than one ','.
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

BiTree removeSubTree(BiTree tree, char chr){
	if(tree==nullptr || tree->data == chr){
		destroyTree(tree);
		return nullptr;
	}
	tree->lchild = removeSubTree(tree->lchild, chr);
	tree->rchild = removeSubTree(tree->rchild, chr);
	return tree;
}
string printTree(BiTree tree){
	string str;
	if(tree==nullptr)
		return str;
	
	str = tree->data;
	if(tree->lchild == nullptr && tree->rchild == nullptr)
		return str;

	str = str + "(" + printTree(tree->lchild);

	if(tree->rchild){
		str = str + "," + printTree(tree->rchild);
	}
	
	str = str + ")";
	
	return str;
}

int main(int argc, char *argv[]){
	string str;
	char chr; 
#ifdef LOCAL_DEBUG
	str = "A(B)";
	chr = 'A';
#else
	getline(cin, str);
	cin >> chr;
#endif
	
	BiTree tree = makeTree(str);
	tree = removeSubTree(tree, chr);
	cout << printTree(tree);
	destroyTree(tree);

#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}
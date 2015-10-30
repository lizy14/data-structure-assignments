#define LOCAL_DEBUG
/*
文件名: 
描　述: 二叉树习题 6.47 按层次遍历二叉树

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
#include <queue>
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


void printTreeByLevels(BiTree tree){
	
	if(tree==nullptr)
		return ;
	queue<BiTNode *> q1;
	
	BiTNode *p = tree;
	q1.push(tree);
	
	cout << p->data << ' ';
	
	while(!q1.empty()){
		queue<BiTNode *> q2;
		while(!q1.empty()){
			p = q1.front();
			q1.pop();
			if(p->lchild){
				q2.push(p->lchild);
				cout << p->lchild->data << ' ';
			}
			if(p->rchild){
				q2.push(p->rchild);
				cout << p->rchild->data << ' ';
			}
		
		};
		q1 = q2;
	}
	return;
}

int main(int argc, char *argv[]){
	string str;
#ifdef LOCAL_DEBUG
	str = "A(B(D),C)";
#else
	getline(cin, str);
#endif

	
	BiTree tree = makeTree(str);
	printTreeByLevels(tree);
	destroyTree(tree);

#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

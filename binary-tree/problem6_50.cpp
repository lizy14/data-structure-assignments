#define LOCAL_DEBUG
/*
文件名: 
描　述: 二叉树习题 6.50 以三元组构建二叉链表

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
using namespace std;

typedef char TElemType; 

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree, *BiTLink;

void destroyTree(BiTree tree){
	if(tree == nullptr)
		return;
	destroyTree(tree->lchild);
	destroyTree(tree->rchild);
	delete tree;
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
BiTree findNode(BiTree root, char chr){
	if(root == nullptr)
		return nullptr;
	if(root->data == chr)
		return root;
	BiTree result;
	result = findNode(root->lchild, chr);
	if(result)
		return result;
	return findNode(root->rchild, chr);
}
BiTree makeTreeFromListOfEdges(){
	BiTree tree=nullptr;
	while(!cin.eof()){
		char F, C, LR;
		cin >> F >> C >> LR;

		if(F=='^' && C=='^')
			break;
		
		BiTree newNode = new BiTNode();
		newNode->lchild = newNode->rchild = nullptr;
		newNode->data = C;

		if(F=='^'){
			tree = newNode;
			continue;
		}

		BiTree parent = findNode(tree, F);
		if(parent==nullptr)
			throw "node not found!";
		if(LR=='L')
			parent->lchild = newNode;
		else
			parent->rchild = newNode;
	}
	return tree;
}

int main(int argc, char *argv[]){
	
	BiTree tree = makeTreeFromListOfEdges();
	cout << printTree(tree);
	destroyTree(tree);

#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

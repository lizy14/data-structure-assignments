#define LOCAL_DEBUG
/*
文件名: 
描　述: 二叉树习题 6.54 满二叉树，以顺序存储结构构建二叉链表

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
#include <vector>
using namespace std;

typedef char TElemType;

typedef vector<TElemType> SqBiTree; //uses subscript starting from 0

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

BiTree makeTreeFromLinearStorage(SqBiTree sqBiTree){
	int length = sqBiTree.size();
	if(length==0)
		return nullptr;

	BiTree newNode=new BiTNode();
	newNode->data = sqBiTree[0];
	
	SqBiTree left;
	SqBiTree right;
	
	/* 
	now lets iterate over `sqBiTree`
	classify items of which into the two groups: 
	items in lchild, or items in rchild
	*/
	int j=1, k=0;
	for(int i=1; i<length; i++){
		if(k<j)
			left.push_back(sqBiTree[i]);
		else
			right.push_back(sqBiTree[i]);
		k++;
		if(2*j==k){
			k=0;
			j*=2;
		}
	}
	newNode->lchild = makeTreeFromLinearStorage(left);
	newNode->rchild = makeTreeFromLinearStorage(right);

	return newNode;
}

int main(int argc, char *argv[]){

	SqBiTree sqBiTree;
	while(!cin.eof()){
		char _;
		cin >> _;
		if(_ == '$')
			break;
		if(cin.good())
			sqBiTree.push_back(_);
		else
			break;
	}

	BiTree biTree = makeTreeFromLinearStorage(sqBiTree);
	cout << printTree(biTree);
	destroyTree(biTree);

#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

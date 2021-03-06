/*
文件名: 
描　述: 二叉搜索树习题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-28

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#ifndef _DEBUG
#define nullptr NULL
#endif

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

class BinarySearchTree;

class BinarySearchTree{
public:
    typedef int TElemType;
    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild, *rchild;
    }BiTNode, *BiTree, *BiTLink;
    typedef vector<BinarySearchTree> Trees;
private:
    BiTree root;
public:
    BinarySearchTree():root(nullptr){}
    BinarySearchTree(string str){
        root = makeTree(str);
    }
    ~BinarySearchTree(){
        destroyTree(root);
    }
    operator string(){
        if(root == nullptr)
            return "";
        return printTree(root);
    }
    void insert(TElemType elem){
        root = insertInto(root, elem);
    }
    Trees split(TElemType d){
        Trees v(2);
        tour(root, d, v);
        return v;
    }
    void makeSureEverythingIsLessThan(TElemType d){
        root = makeSureEverythingIsLessThanIn(root, d);
    }
protected:
    void tour(BiTLink t, TElemType d, Trees& v){
        if(t == nullptr)
            return;
        if(t->data <= d)
            v[0].insert(t->data);
        else
            v[1].insert(t->data);
        tour(t->lchild, d, v);
        tour(t->rchild, d, v);
    }
    BiTree insertInto(BiTree t, TElemType e){
        if(t == nullptr){
            t = new BiTNode();
            t->data = e;
            t->lchild = t->rchild = nullptr;
            return t;
        }
        if(e < t->data){
            t->lchild = insertInto(t->lchild, e);
            return t;
        }
        if(e > t->data){
            t->rchild = insertInto(t->rchild, e);
            return t;
        }
        return t;
    }
    BiTree makeSureEverythingIsLessThanIn(BiTree t, TElemType d){
        if(t == nullptr){
            return t;
        }
        if(d < t->data){
            destroyTree(t);
            return nullptr;
        }else if(d > t->data){
            t->rchild = makeSureEverythingIsLessThanIn(t->rchild, d);
            return t;
        }else{//d == t.data
            BiTree newNode = t->lchild;
            destroyTree(t->rchild);
            delete t;
            return newNode;

        }
    }
    BiTree makeTree(const string& str){
	    int len = str.length();
	    if(len == 0 || str[0]=='-')
		    return nullptr;
	
	    BiTree tree = new BiTNode();

        int left = str.find('(');

        int data = atoi(str.substr(0, left).c_str());
	    tree->data = data;	
	    tree->lchild = tree->rchild = nullptr;

	    if(left == string::npos)
		    return tree;


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
    string printTree(BiTree tree){
        stringstream ss;
        if(tree==nullptr){
            ss << '-';
            return ss.str();
        }

        ss << tree->data;

        if(tree->lchild == nullptr && tree->rchild == nullptr)
            return ss.str();

        ss 
            << "(" 
            << printTree(tree->lchild)
            << "," 
            << printTree(tree->rchild)
            << ")";

        return ss.str();
    }
    void destroyTree(BiTree tree){
        if(tree == nullptr)
            return;
        destroyTree(tree->lchild);
        destroyTree(tree->rchild);
        delete tree;
    }
    void replace_all(string & s, string const & t, string const & w){  
        int pos = s.find(t), t_size = t.size(), r_size = w.size();  
        while(pos != string::npos){ // found   
            s.replace(pos, t_size, w);   
            pos = s.find(t, pos + r_size );   
        }
    }
};




int main(){

    string str;
    int elem;
#ifdef _DEBUG
    str = "5(2,8)";
    elem = 3;
#else
    getline(cin, str);
    cin >> elem;
#endif

    BinarySearchTree tree(str);

    //tree.insert(elem);
    //tree.makeSureEverythingIsLessThan(elem);
    BinarySearchTree::Trees trees = tree.split(elem);

    //cout << (string)tree;
    cout << (string)trees[0] << endl << (string)trees[1] << endl;

#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}
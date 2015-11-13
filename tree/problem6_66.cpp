/*
文件名: 
描　述: 数据结构习题6.66：将一个使用双亲表示的树转化为使用孩子兄弟链表表示

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-13

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#ifndef _DEBUG
#define nullptr NULL
#endif

#include <iostream>
#include <vector>
using namespace std;


typedef int ElemType;

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
    CSNode():firstchild(nullptr),nextsibling(nullptr){}
}CSNode;
typedef vector<CSNode> CSTree;
/*
uses subscript 1 to n
&operator[](1) points to the root node.
number of nodes saved in operator[](0).data
if n==0, it's an empty vector
*/

typedef struct PTNode{
    ElemType data;
    int parent;
};
/*
uses subscript 1 to n. 
number of nodes saved in operator[](0).data
id of the root node saved in operator[](0).parent
if n==0, it's an empty vector
*/
typedef vector<PTNode> PTree;

PTree createPTree(){
    PTree tree;
    int n;
    cin >> n;
    if(n==0 || !cin.good())
        return tree;
    
    PTNode node;
    node.data = n;
    tree.push_back(node);

    for(int i=1; i<=n; i++){
        int p;
        cin >> p;
        node.parent = p;
        if(p==0)
            tree[0].parent = i;
        node.data = i;
        tree.push_back(node);
    }
    return tree;
}
CSTree createCSTree(PTree pTree){
    CSTree tree;
    if(pTree.size()==0)
        return tree;
    tree.resize(pTree.size());
    for(int i=1; i<pTree.size(); i++){
        int p = pTree[i].parent;
        //now, i is a child of p
        if(p==0){
            tree[1].data = i;
            continue;
        }

        CSNode **q = &tree[p].firstchild;
        while(*q != nullptr)
            q = &((*q)->nextsibling);
        *q = &tree[i];
        (*q)->data = i;

    }
    return tree;
}

int getNodeId(CSNode* node){
    if(node==nullptr)
        return 0;
    else
        return node->data;
}
void printTree(CSTree tree){
    for(int i=1; i<tree.size(); i++){
        cout
            << getNodeId(tree[i].firstchild)
            << ' '
            << getNodeId(tree[i].nextsibling)
            << '\n';
    }
}
int main(){
    PTree pTree = createPTree();
    CSTree csTree = createCSTree(pTree);
    printTree(csTree);
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}

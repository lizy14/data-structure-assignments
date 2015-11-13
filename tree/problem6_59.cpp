/*
文件名: 
描　述: 数据结构习题6.59：无重复地输出以孩子兄弟链表存储的树中所有的边

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
struct Edge{
    int a, b;
    Edge(int a_, int b_){a = a_, b = b_;}
};

typedef vector<vector<Edge> > Edges;

typedef int ElemType;

typedef struct CSNode {
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
/*
CSTree is an array of CSNode, uses subscript 1 to n
&operator[](1) points to the root node.
number of nodes saved in operator[](0).data
*/
CSTree createTree(){
    int n;
    cin >> n;
    if(n==0 || !cin.good())
        return nullptr;
    
    CSTree nodes = new CSNode[n+1]; 
    nodes[0].data = n;

    for(int i=1; i<=n; i++){
        int c, s;
        cin >> c >> s;
        nodes[i].firstchild = c? &nodes[c]: nullptr;
        nodes[i].nextsibling = s? &nodes[s]: nullptr;
        nodes[i].data = i;
    }
    return nodes;
}
void destroyTree(CSTree tree){
    delete[] tree;
}


//to be called recursively.
void printEdgesOfSubTree(CSNode *root, Edges& edges, int depth){
    if(root==nullptr)
        return;
    CSNode *p;
    p = root->firstchild;
    while(p!=nullptr){
        if(edges.size()<depth+1)
            edges.resize(depth+1);
        edges[depth].push_back(Edge(root->data, p->data));
        p = p->nextsibling;
    }
    p = root->firstchild;
    while(p!=nullptr){
        printEdgesOfSubTree(p, edges, depth+1);
        p = p->nextsibling;
    }
    
}

void printEdges(CSTree tree){
    if(tree==nullptr)
        return;
    Edges edges;
    printEdgesOfSubTree(&tree[1], edges, 0);
    for(int i=0; i<edges.size(); i++){
        for(int j=0; j<edges[i].size(); j++){
            cout << edges[i][j].a << ' ' <<  edges[i][j].b << '\n';
        }
    }
}

int main(){
    CSTree tree = createTree();
    printEdges(tree);
    destroyTree(tree);
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}

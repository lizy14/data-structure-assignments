/*
�ļ���: 
�衡��: ���ݽṹϰ��ϰ��6.60��ͳ�ƺ���-�ֵ�����洢����T��Ҷ�ӵĸ���

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-11-13

������: Visual Studio 2012 (MSVC++ 11.0)
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

int countLeafNodes(CSTree tree){
    int n=tree[0].data;
    int count = 0;
    for(int i=1; i<n; i++){
        if(tree[i].firstchild==nullptr)
            count ++;
    }
    return count;
}
int main(){
    CSTree tree = createTree();
    cout << countLeafNodes(tree);
    destroyTree(tree);
#ifdef _DEBUG
    system("pause");
#endif
    return 0;
}

/*
文件名: 
描　述: Prim 算法寻找无向图的一棵最小生成树

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-07

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>


typedef int weight;
typedef int nodeID;

struct Edge{
    nodeID a, b;
    Edge(nodeID a_, nodeID b_):a(a_), b(b_){}
    Edge(){}
};

bool operator<(Edge x, Edge y){
    if(x.a < y.a)
        return true;
    else if(x.a == y.a)
        return x.b < y.b;
    else 
        return false;
}

class Graph{
public:
    
private:
    std::vector<std::vector<weight> > matrixAdjacency; //邻接矩阵

    std::set<weight> V;//（已放入）最小生成树中的顶点
    std::vector<Edge> T;//（已放入）最小生成树中的边

    nodeID startingPoint;
    int nEdges, nVertexes;
public:
    static const weight INFINITY = 1000000/2;
public:
    void read(std::istream&);
    void printMatrix(std::ostream&);
	
    void prim();
    void printTree(std::ostream&);

    weight& getWeight(nodeID start, nodeID end){
        return matrixAdjacency[start][end];
    }
    Graph():
        matrixAdjacency(NULL),
        nEdges(0),
        nVertexes(0){}
    ~Graph(){}
};
void Graph::prim(){
    V.clear();
    T.clear();

    V.insert(0);
    while(V.size()!=nVertexes){
        nodeID a, b;
        weight shortestEdge = -1;
        for(int i=0; i<nVertexes; i++){
            if(V.find(i)==V.end())
                continue;
            //i is in V
            for(int j=0; j<nVertexes; j++){
                if(V.find(j)!=V.end())
                    continue;
                if(i==j)
                    continue;
                //now nodeID i is in V, while j is not
                weight distance = getWeight(i, j);
                if(distance <shortestEdge || shortestEdge == -1){
                    a = i, b = j;
                    shortestEdge = distance;
                }
            }
        }
        T.push_back(Edge(a, b));
        V.insert(b);

    }
}
void Graph::printMatrix(std::ostream& s){
	s << "Matrix" << std::endl;
    for(int i=0; i<nVertexes; i++){
        for(int j=0; j<nVertexes; j++){
            s << matrixAdjacency[i][j] <<' ';
        }
        s << std::endl;
    }
}
void Graph::printTree(std::ostream& s){
    weight total = 0;
    for(int j=0; j<T.size(); j++){
        Edge &i = T[j];
        total += getWeight(i.a, i.b);
        if(i.a > i.b){
            nodeID t;
            t = i.a, i.a = i.b, i.b = t;
            int x = 1;
        }
    }

    std::sort(T.begin(), T.end());
    s << total << '\n';
    for(int j=0; j<T.size(); j++){
        Edge &i = T[j];
        s << i.a << '-' << i.b << ' ';
    }

}
void Graph::read(std::istream& s){
    s >> nVertexes >> nEdges;
    
    //make an n*n matrix
    matrixAdjacency.resize(nVertexes);

    //for(auto& i : matrixAdjacency){
    for(int j=0; j<nVertexes; j++){
        matrixAdjacency[j].resize(nVertexes, INFINITY);
    }
    
    int _1, _2, _3;
    for(int i=0; i<nEdges; i++){
        s >> _1 >> _2 >> _3;
        matrixAdjacency[_1][_2] = _3;
        matrixAdjacency[_2][_1] = _3;
    }
}
int test(std::istream& s){
    Graph graph;
    graph.read(s);

    graph.prim();
    graph.printTree(std::cout);

    return 0;
}
int main(){
#ifndef _DEBUG
    //for online judge
    return test(std::cin);
#else
    //for local debug
    std::ifstream file("input.txt");
    return test(file) || system("pause");
#endif
}
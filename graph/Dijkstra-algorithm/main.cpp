#define _DEBUG
/*
文件名: 
描　述: Dijkstra 算法求正权有向图中某点到其他点之间的最短路径
　　　  采用邻接矩阵表示图

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-10

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <fstream>
#include <vector>

class Graph{
    int **matrixAdjacency; //邻接矩阵
    int nEdges, nVertexes;
public:
    static const int INFINITY = 1000000/2;
public:
    void read(std::istream&);
	void dijkstra(int);
    void printMatrix(std::ostream&);
    Graph():
        matrixAdjacency(NULL),
        nEdges(0),
        nVertexes(0){}
    ~Graph();
};
void Graph::dijkstra(int startingPoint){
	return;
}
Graph::~Graph(){
    if(matrixAdjacency){
        for(int i=0; i<nVertexes; i++){
            delete[] matrixAdjacency[i];
        }
        delete[] matrixAdjacency;
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
void Graph::read(std::istream& s){
    s >> nVertexes >> nEdges;
    
    //make an n*n matrix
    matrixAdjacency = new int*[nVertexes];
    for(int i=0; i<nVertexes; i++){
        matrixAdjacency[i] = new int[nVertexes];
		for(int j=0; j<nVertexes; j++)
			matrixAdjacency[i][j]=0;
    }
    
    int _1, _2, _3;
    for(int i=0; i<nEdges; i++){
        s >> _1 >> _2 >> _3;
        matrixAdjacency[_1][_2] = _3;
    }
}
int test(std::istream& s){
    Graph graph;
    graph.read(s);
    graph.printMatrix(std::cout);
    int n, startingPoint, endingPoint;
	s >> n >> startingPoint;
    graph.dijkstra(startingPoint);
    for(int i=0; i<n; i++){
        s >> endingPoint;
        //output here
    }
    return 0;
}
int main(){
    //for online judge
#ifndef _DEBUG
    return test(std::cin);
#endif
    //for local debug
    std::ifstream file("input.txt");
    return test(file);
}
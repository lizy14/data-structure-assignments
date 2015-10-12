/*
文件名: 
描　述: Warshall 算法求有向赋权图上两点间的最短路
　　　  采用邻接矩阵表示图

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-12

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <fstream>

class Graph{
public:
    int **matrix; //adjacency matrix
    int nEdges, nVertexes;
public:
    static const int NO_PATH = -1;
public:
    void read(std::istream&);
    int lengthOfShortestPath(int vertexA, int vertexB);
    void printMatrix(std::ostream&);
    Graph():
        matrix(NULL),
        nEdges(0),
        nVertexes(0){}
    ~Graph();
};
int Graph::lengthOfShortestPath(int vertexA, int vertexB){
    if(vertexA == vertexB)
        return 0;
    //TODO: 
    return NO_PATH;
}
Graph::~Graph(){
    if(matrix){
        for(int i=0; i<nVertexes; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}
void Graph::printMatrix(std::ostream& s){
    for(int i=0; i<nVertexes; i++){
        for(int j=0; j<nVertexes; j++){
            s << matrix[i][j] <<' ';
        }
        s << std::endl;
    }
}
void Graph::read(std::istream& s){
    s >> nVertexes >> nEdges;
    
    //make matrix a n*n array
    matrix = new int*[nVertexes];
    for(int i=0; i<nVertexes; i++){
        matrix[i] = new int[nVertexes];
		for(int j=0; j<nVertexes; j++)
			matrix[i][j]=0;
    }
    
    int _1, _2, _3;
    for(int i=0; i<nEdges; i++){
        s >> _1 >> _2 >> _3;
        matrix[_1-1][_2-1] = _3;
    }
}
int test(std::istream& s){
    Graph graph;
    graph.read(s);
    
    int _, _1, _2, __;
	s >> _;
    for(int i=0; i<_; i++){
        s >> _1 >> _2;
        __ = graph.lengthOfShortestPath(_1-1, _2-1);
        if(__ == Graph::NO_PATH)
            std::cout << "NO PATH" << std::endl;
        else
            std::cout << __ << std::endl;
    }
    return 0;
}
int main(){
    //for online judge
    //return test(std::cin);
    
    //for local debug
    std::ifstream file("input.txt");
    test(file);
    return system("pause");
}
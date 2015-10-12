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
#include <algorithm>

#include <stdlib.h>


class Graph{
    int **matrixAdjacency; //邻接矩阵
	int **matrixD; //最短路径权重矩阵
    int nEdges, nVertexes;
public:
    static const int INFINITY = 1000000/2;
public:
    void read(std::istream&);
    int lengthOfShortestPath(int vertexA, int vertexB);
	void warshall();
    void printMatrix(std::ostream&);
    Graph():
        matrixAdjacency(NULL),
		matrixD(NULL),
        nEdges(0),
        nVertexes(0){}
    ~Graph();
};
void Graph::warshall(){
	//make an n*n matrix
	matrixD = new int*[nVertexes];
	for(int i=0; i<nVertexes; i++){
		matrixD[i] = new int[nVertexes];
		for(int j=0; j<nVertexes; j++)
			if(i==j)
				matrixD[i][j]=0;
			else if(matrixAdjacency[i][j])
				matrixD[i][j]=matrixAdjacency[i][j];
			else
				matrixD[i][j]=INFINITY;
	}

	//here we go
	int a, b;
	for(int k=0; k<nVertexes; k++){
		for(int j=0; j<nVertexes; j++){
			for(int i=0; i<nVertexes; i++){
					a = matrixD[i][j];
					b = matrixD[i][k]+matrixD[k][j];
					matrixD[i][j] = std::min(a, b);
			}
		}
	}
	return;
}
int Graph::lengthOfShortestPath(int vertexA, int vertexB){
    return matrixD[vertexA][vertexB];
}
Graph::~Graph(){
    if(matrixAdjacency){
        for(int i=0; i<nVertexes; i++){
            delete[] matrixAdjacency[i];
        }
        delete[] matrixAdjacency;
    }
	if(matrixD){
		for(int i=0; i<nVertexes; i++){
			delete[] matrixD[i];
		}
		delete[] matrixD;
	}
}
void Graph::printMatrix(std::ostream& s){
	s << "Matrix" << std::endl;
    for(int i=0; i<nVertexes; i++){
        for(int j=0; j<nVertexes; j++){
            s << matrixD[i][j] <<' ';
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
        matrixAdjacency[_1-1][_2-1] = _3;
    }
}
int test(std::istream& s){
    Graph graph;
    graph.read(s);
    graph.warshall();
    int _, _1, _2, __;
	s >> _;
    for(int i=0; i<_; i++){
        s >> _1 >> _2;
        __ = graph.lengthOfShortestPath(_1-1, _2-1);
        if(__ >= Graph::INFINITY)
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
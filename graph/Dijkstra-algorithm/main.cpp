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
#include <set>
#include <stack>

class Graph{
    typedef int weight;
    typedef int nodeID;
    std::vector<std::vector<weight> > matrixAdjacency; //邻接矩阵
    std::vector<nodeID> Q;//单源最短路径信息
    std::vector<weight> pi;//单源最短路径的长度
    nodeID startingPoint;
    int nEdges, nVertexes;
public:
    static const weight INFINITY = 1000000/2;
public:
    void read(std::istream&);
    void printMatrix(std::ostream&);
	
    void dijkstra(nodeID);
    weight getPathLength(nodeID destination){
        if(destination==startingPoint)
            return 0;
        return pi[destination];
    }
    std::vector<nodeID> getPath(nodeID destination){
        std::vector<nodeID> vector;
        std::stack<nodeID> stack;
        
        nodeID p = destination;
        while(Q[p]!=startingPoint){
           stack.push(Q[p]);
           p = Q[p];
        }
        while(!stack.empty()){
            vector.push_back(stack.top());
            stack.pop();
        }
        return vector;
    }
    
    weight& getWeight(nodeID start, nodeID end){
        return matrixAdjacency[start][end];
    }
    Graph():
        matrixAdjacency(NULL),
        nEdges(0),
        nVertexes(0){}
    ~Graph(){}
};
void Graph::dijkstra(nodeID startingPoint_){
    startingPoint = startingPoint_;

    std::set<nodeID> T;
    for(int i=0; i<nVertexes; i++){
        if(i!=startingPoint)
            T.insert(i);
    }

    pi.resize(nVertexes);
    for(int i=0; i<nVertexes; i++){
        pi[i]=getWeight(startingPoint,i);
    }

    Q.resize(nVertexes, startingPoint);

    //initialization done. here comes the main loop

    while(T.size()!=0){
        //find the node inside T with minimal pi
        int minPi = INFINITY;
        int minID = *T.begin();
        
        //for(auto& i: T){
        //fuck the OJ platform not supporting  `--std=c++11`
        for(
            std::set<nodeID>::iterator j=T.begin(); 
            j!=T.end(); j++){
            nodeID i = (*j);
            if(pi[i]<minPi){
                minID = i;
                minPi = pi[i];
            }
        }

        //found it.
        T.erase(T.find(minID));
        

        //modify T and Q
        //for(auto& i: T){
        for(
            std::set<nodeID>::iterator j=T.begin(); 
            j!=T.end(); j++){
            nodeID i = (*j);
            weight possibleNewPi = pi[minID] + getWeight(minID, i);
            if(possibleNewPi < pi[i]){
                pi[i]=possibleNewPi;
                Q[i] = minID;
            }
        }
    }

	return;
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
    matrixAdjacency.resize(nVertexes);

    //for(auto& i : matrixAdjacency){
    for(int j=0; j<nVertexes; j++){
        matrixAdjacency[j].resize(nVertexes, INFINITY);
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

    int n, startingPoint, endingPoint;
	s >> n >> startingPoint;

    graph.dijkstra(startingPoint);
    for(int i=0; i<n; i++){
        s >> endingPoint;
        int length = graph.getPathLength(endingPoint);
        if(length>=Graph::INFINITY){
            std::cout << "NO PATH\n";
            continue;
        }
        std::cout << startingPoint << "-";
        std::vector<int> path = graph.getPath(endingPoint);
        for(int i=0; i<path.size(); i++){
            std::cout << path[i] << '-';
        }
        std::cout << endingPoint << ' ' << length << '\n';
    }
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
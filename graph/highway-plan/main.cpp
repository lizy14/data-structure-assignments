/*
文件名: 
描　述: 图论上机作业 高速公路规划问题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-07

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
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

typedef int weight;
typedef int nodeID;

struct Edge{
    int id;
    nodeID a, b;
    Edge(nodeID a_, nodeID b_, int id_=0):a(a_), b(b_), id(id_){}
    Edge(){}
};

bool operator<(Edge x, Edge y){
    if(x.a >= x.b){
        int t = x.a; x.a = x.b, x.b = t;
    }
    if(y.a >= y.b){
        int t = y.a; y.a = y.b, y.b = t;
    }
    if(x.a < y.a)
        return true;
    else if(x.a == y.a)
        return x.b < y.b;
    else 
        return false;
}


class Graph{
    std::set<Edge> edges;
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
    void highway(std::ostream& s);

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
    Q.clear();
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
        matrixAdjacency[_2][_1] = _3;
        edges.insert(Edge(_1, _2, i));
    }
}
void Graph::highway(std::ostream& s){
    std::set<Edge> useful;
    for(int i=0; i<nVertexes; i++){
        dijkstra(i);
        for(int j=0; j<nVertexes; j++){
            if(i>=j)
                continue;
            //shortest path from i to j
            std::vector<nodeID> path = getPath(j);
            if(path.size()==0){
                useful.insert(Edge(i, j));
            }else{
                useful.insert(Edge(i, path[0]));
                useful.insert(Edge(path[path.size()-1], j));
                for(int k=0; k<(int)path.size()-2; k++)
                    useful.insert(Edge(path[k], path[k+1]));  
            }

        }
    }
    bool found = false;
    for(std::set<Edge>::iterator j = edges.begin(); j!=edges.end(); j++){
        Edge i = *j;
        if(useful.find(i)==useful.end())
            found = true, s << i.id << '\n';
    }
    if(!found)
        s << "NOT FOUND";
}
int test(std::istream& s){
    Graph graph;
    graph.read(s);

    graph.highway(std::cout);
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
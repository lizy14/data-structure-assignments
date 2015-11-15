/*
文件名: 
描　述: PT 图
　　　  给定各工序的时间和先序工序，
　　　  求关键路径及各个工序允许延误的时间

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-10

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class PTGraph{
    typedef int nodeID;
    typedef int time;
    typedef struct{
        std::vector<nodeID> dependencies;//先序工序
        time timeCost;//本工序耗时
    } procedure;

    std::vector<procedure> procedures;
    int nProcedures;
    std::vector<nodeID> nodeIdTranslation; 
   
public:
    PTGraph()
        {}
    
    void findCriticalPath(){

    }
    void read(std::istream& s){
        s >> nProcedures;

        procedures.resize(nProcedures);
        
        std::string line;
        std::getline(s, line);

        for(int i=0; i<nProcedures; i++){
            std::getline(s, line);
            std::stringstream stream(line);
            nodeID id;
            time time_;
            stream >> id >> time_;
            procedures[id].timeCost = time_;
            while(233){
                nodeID dependency;
                stream >> dependency;
                if(stream.fail())
                    break; 
                procedures[id].dependencies.push_back(dependency);
                char comma;
                stream >> comma;
                if(stream.fail())
                    break; 
                if(comma!=',')
                    throw "invalid syntax";
            }
        }
    }
};

int test(std::istream& s){
    PTGraph graph;
    graph.read(s);
    return 0;
}
int main(){
    
#ifndef _DEBUG
    //for online judge
    return test(std::cin);
#else
    //for local debug
    std::ifstream file("input.txt");
    return test(file),system("pause"),0;
#endif
}
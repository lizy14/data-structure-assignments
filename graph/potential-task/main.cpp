/*
文件名: 
描　述: PT 图
　　　  给定各工序的时间和先序工序，
　　　  求关键路径及各个工序允许延误的时间

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-10

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

class PTGraph{
    typedef int nodeID;
    typedef int time;
    typedef std::vector<nodeID> path;
    typedef std::vector<path> paths;

    struct procedure{
        // i -> j: j depends upon i, i is depended by j.

        std::set<nodeID> dependUpon;//依赖的工序，PT图中的前驱
        std::set<nodeID> dependedBy;//依赖于本工序的工序，PT图中的后继
        time timeCost;              //本工序耗时
        
        time pi, tau, t;//本工序的最早启动时间、最晚启动时间、允许延误时间

        procedure():pi(0),tau(std::numeric_limits<int>::max()){}
        bool find_(std::set<int>& s,int i){return s.find(i)!=s.end();}
        bool dependsUpon(nodeID i){return find_(dependUpon, i);}
        bool isDependedBy(nodeID i){return find_(dependedBy, i);}
    };

    std::vector<procedure> procedures;
    int nProcedures;

    //maps from a node's _original ID_ to its _ID after topological sort_
    std::vector<nodeID> map; 
    
    //stores a node's dependency(s) in critical path(s)
    std::vector<std::vector<nodeID> > Q; 

public:
    
    /*
    topological sort
    makes sure that if procedure i is depended by j (i -> j),
    map[i] < map[j]
    */
    void sortProcedures(){
        map.resize(0);
        std::set<nodeID> deletedNodes;

        //find a node depend upon no one
        while(deletedNodes.size() <= nProcedures){
            for(int i=0; i <= nProcedures; i++){
                if(std::find(deletedNodes.begin(),deletedNodes.end(),i)!=deletedNodes.end())
                    continue;

                std::vector<nodeID> dependUponCurrently;
                for(std::set<nodeID>::iterator it = procedures[i].dependUpon.begin(); 
                    it != procedures[i].dependUpon.end(); it++){
                    nodeID j = *it;
                    if(deletedNodes.find(j)==deletedNodes.end()){
                        dependUponCurrently.push_back(j);
                    }
                }
                
                if(dependUponCurrently.empty()){
                    //found it.
                    deletedNodes.insert(i);// delete it from the graph 
                    map.push_back(i);      // and send it to the sequence of sorted nodes
                    break;
                }
            }
        }
    }
    void exec(){
        sortProcedures();
        //calculate pi
        Q.resize(nProcedures+1,std::vector<nodeID>(1,-1));
        procedures[map[0]].pi = 0;
        for(int j_=1; j_<=nProcedures; j_++){
            nodeID j = map[j_];
            for(std::set<nodeID>::iterator it = procedures[j].dependUpon.begin(); 
                it != procedures[j].dependUpon.end(); it++){
                nodeID i = *it;
                // i -> j
                time possibleNewPi = procedures[i].pi + procedures[i].timeCost;
                if(possibleNewPi > procedures[j].pi){
                    procedures[j].pi = possibleNewPi;
                    Q[j].resize(1);
                    Q[j][0]=i;
                }else if(possibleNewPi == procedures[j].pi){
                    procedures[j].pi = possibleNewPi;
                    Q[j].push_back(i);
                }
            }
        }

        //calculate tau
        procedures[map[nProcedures]].tau = procedures[map[nProcedures]].pi;
        for(int j_=nProcedures-1; j_>=0; j_--){
            nodeID j = map[j_];
            for(std::set<nodeID>::iterator it = procedures[j].dependedBy.begin(); 
                it != procedures[j].dependedBy.end(); it++){
                nodeID i = *it;
                // j -> i
                time possibleNewTau = procedures[i].tau - procedures[j].timeCost;
                if(possibleNewTau < procedures[j].tau){
                    procedures[j].tau = possibleNewTau;
                }
            }
        }

        //calculate t
        for(int i=0; i<=nProcedures; i++){
            procedures[i].t = procedures[i].tau - procedures[i].pi;
        }
    }
    void read(std::istream& s){
        s >> nProcedures;

        //there is a virtual procedure: ending point
        procedures.resize(nProcedures+1);
        
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
                procedures[id].dependUpon.insert(dependency);
                procedures[dependency].dependedBy.insert(id);
                char comma;
                stream >> comma;
                if(stream.fail())
                    break; 
                if(comma!=',')
                    throw "invalid syntax";
            }
        }
        
        //add edges to the virtual procedure
        for(int i=0; i<nProcedures; i++){
            if(procedures[i].dependedBy.empty()){
                procedures[i].dependedBy.insert(nProcedures);
                procedures[nProcedures].dependUpon.insert(i);
            }
        }
    }

    paths getPath(){
        paths ret;
        
        std::vector<int> Qit; //which one in Q[p][] to visit
        Qit.resize(nProcedures+1, 0);
        bool flag = false; //whether there's another path to find

        do{
            path vector;
            std::stack<nodeID> stack;
            nodeID p = map[nProcedures]; //currently visiting node
            flag = false;
            
            while(true){
                int i = Qit[p];
                if(Q[p][i]==-1)
                    break;
                stack.push(Q[p][i]);
                if(Qit[p]+1 < Q[p].size() ){
                    flag = true;
                    Qit[p]++;
                }
                p = Q[p][i];
            }
            
            while(!stack.empty()){
                vector.push_back(stack.top());
                stack.pop();
            }
        
            ret.push_back(vector);
        }while(flag);
        return ret;
    }
    void write(std::ostream& s){

        s << procedures[nProcedures].pi << '\n';
        //construct criticalPaths
        paths criticalPath = getPath();
        std::vector<std::string> criticalPathStrings(criticalPath.size());

        //translate into output format 
        for(int j=0; j<criticalPath.size(); j++){
            std::stringstream ss;
            for(int i=0; i<criticalPath[j].size(); i++)
                ss << criticalPath[j][i] << '-';
            ss << "end\n";
            criticalPathStrings[j] = ss.str();
        }
        //sort them
        std::sort(criticalPathStrings.begin(), criticalPathStrings.end());
        //and print them
        for(int j=0; j<criticalPath.size(); j++){
            s << criticalPathStrings[j];
        }

        //print t
        for(int i=0; i<nProcedures; i++)
            s << procedures[i].t << '\n';
    }
};

int test(std::istream& s){
    PTGraph graph;
    graph.read(s);
    graph.exec();
    graph.write(std::cout);
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

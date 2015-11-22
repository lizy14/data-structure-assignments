/*
文件名: 
描  述: 数据结构习题9.29

作  者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-20

环  境: 
*/


#include <iostream>
using namespace std;



class SSTable{
    typedef int KeyType;
    typedef int DataType;
    
    typedef struct{
        KeyType key;
        DataType data;
    }ElemType;

    ElemType *elem;
    int length;

    public:
    SSTable(istream& s){
        s >> length;
        elem = new ElemType[length];
        for(int i=0; i<length; i++){
            s >> elem[i].key;
        }
    }
    ~SSTable(){
        delete[] elem;
    }
    int find(KeyType key){
        static KeyType lastQuery=0;
        if(lastQuery<0)
            lastQuery = 0;
        if(lastQuery>=length)
            lastQuery = length-1;
        KeyType p = lastQuery;
        
        if(key == elem[p].key)
            return p;
        else if(key < elem[p].key){
            while(key <= elem[p].key && p>=0){
                if(key == elem[p].key)
                    return p;   
                p--;
                lastQuery--;
            }
            return -1;
        }else if(key > elem[p].key){
            while(key >= elem[p].key && p<length){
                if(key == elem[p].key)
                    return p;   
                p++;
                lastQuery++;
            }
            return -1;
        }
    }
};

int main(int argc, char *argv[]){
    SSTable table(cin);
    int _;
    cin >> _;
    for(int __=0; __<_; __++){
        int ___;
        cin >> ___;
        cout << table.find(___)+1 << endl;
    }
    return 0;
}

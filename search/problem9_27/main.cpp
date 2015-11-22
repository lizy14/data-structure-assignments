/*
�ļ���: 
�衡��: ���ݽṹϰ��9.29���޸ĵ�˳�����ֲ���

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-11-20

������: Visual Studio 2012 (MSVC++ 11.0)
*/


#include <iostream>
#include <fstream>
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
        if(key < elem[0].key)
            return -1;
        if(elem[length-1].key < key)
            return length;

        int low, high, mid;
        
        low=0, high=length-1;
        mid = (low+high)/2;

        while(233){

            if(elem[mid].key <= key && key <= elem[mid+1].key)
                return mid;
            if(key > elem[mid].key){
                low = mid;
                mid = (low+high)/2;
            }else{
                high = mid;
                mid = (low+high)/2;
            }
        }

    }
};

int main(int argc, char *argv[]){
#ifdef _DEBUG
    ifstream stream("input.txt");
#else
    istream& stream = cin;
#endif
    SSTable table(stream);
    int _;
    stream >> _;
    cout << table.find(_)+1;
    return 0;
}

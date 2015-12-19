/*
文件名: 
描　述: 归并排序

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-19

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Vector : public vector<T>{
    void merge(Vector& v, Vector& result, int startOfA, int endOfA, int endOfB){
        int k = startOfA;  //cursor in result
        int i = startOfA;  //cursor in A
        int j = endOfA + 1;//cursor in B
        for(; i<=endOfA && j <= endOfB; k++){
            result[k] = v[i]<v[j]? v[i++]: v[j++];
        }
        if(i <= endOfA) //something left in A
            for(int _=0; _<=(endOfB-k); _++){
                result[k+_] = v[i+_];
            }
        if(j <= endOfB) //something left in B
            for(int _=0; _<=(endOfB-k); _++){
                result[k+_] = v[j+_];
            }
    }
    void mergeAll(Vector& v, Vector& result, int len){
        //v is regarded as a series of sequences whose lenth == `len`
        int size = v.size();
        int i = 0;
        while (i+2*len <= size-1) {
            merge(v, result,  i, i+len-1, i+2*len-1 ) ;
            i += 2 * len;
        }
        if ( i+len <= size-1 )
            merge(v, result, i, i+len-1, size-1);
        else 
            for(int j = i; j <= size-1; j++)
                result[j] = v[j]; 
    }
public:
    void mergeSort(){
        Vector<int> temp;
        int size = this->size();
        temp.resize(size);

        int len = 1;
        while ( len < size ) {
            mergeAll (*this, temp, len );
            len *= 2;
            mergeAll (temp, *this, len );
            len *= 2;                  
        }
    }
};

template <class T>
istream& operator>>(istream& s, Vector<T>& v){
    int n;
    s >> n;
    v.resize(n);
    int i = 0;
    while(i < n){
        s >> v[i];
        i++;
    }
    return s;
}

template <class T>
ostream& operator<<(ostream& s, Vector<T>& v){
    int i = 0;
    while(i < v.size()){
        s << v[i] << ' ';
        i++;
    }
    return s << endl;
}

int main(){
    Vector<int> v;
    cin >> v;
    v.mergeSort();
    cout << v;

    return 0;
}

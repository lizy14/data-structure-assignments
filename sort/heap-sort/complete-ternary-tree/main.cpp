/*
文件名: 
描　述: 堆排序，顺序存储结构的完全三叉树

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-19

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Heap3 : public vector<T>{
public:
    
    void adjust(int s, int m){
        Heap3<T>& H = *this;
        int rc = H[s-1];
        for(int j = 3*s-1; j <= m; j = j* 3 - 1){


            //ugly code :(
            //try to find which subtree to go
            int newj = j;
            if (j + 1 < m) {
                if (H[j] > H[newj-1]) {
                    newj = j + 1;
                }
                if (H[j+1] > H[newj-1]) {
                    newj = j + 2;
                }
            } else if (j < m) {
                if (H[j] > H[j-1]) {
                    newj = j + 1;
                }
            }
            j = newj;

            if(rc > H[j-1])
                break;
            H[s-1] = H[j-1];
            s = j;
        }
        outside_break:
        H[s-1] = rc;
    }
    void insert(T e){
        this->push_back(e);
        for(int i = this->size(); i>0; --i)
            adjust(i, this->size());
    }
    vector<T> heapSort(){
        Heap3<T> r = *this;
        for(int i = r.size(); i>1; --i){
            std::swap(r[0], r[i-1]);
            r.adjust(1, i-1);
        }
        return r;
    }
};

template <class T>
istream& operator>>(istream& s, vector<T>& v){
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
ostream& operator<<(ostream& s, vector<T>& v){
    int i = 0;
    while(i < v.size()){
        s << v[i] << ' ';
        i++;
    }
    return s << endl;
}


int main(){
    int n;
    cin >> n;
    Heap3<int> heap;
    for(int i=0; i<n; i++){
        int _;
        cin >> _;
        heap.insert(_);
    }
    vector<int> v = heap.heapSort();
    cout << v;
    return 0;
}
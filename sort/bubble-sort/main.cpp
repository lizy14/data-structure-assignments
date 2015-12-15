/*
文件名: 
描　述: 数据结构习题，冒泡排序变式

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-15

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <vector>
using namespace std;

template<class T>
vector<T> getVector(istream& s){
    vector<T> v;
    int n;
    s >> n;
    for(int i=0; i<n; i++){
        int _;
        s >> _;
        v.push_back(_);
    }
    return v;
}

template<class T>
ostream& operator<<(ostream& s, vector<T> v){
    for(int i=0; i<v.size(); i++)
        s << v[i] << ' ';
    return s << endl;
}



template<class T>
int bubbleSort(vector<T>& arr) {
    int count = 0;
    int cursor = arr.size() - 1;
    while (cursor > 0) {

        int modification = 0; //position of latest modification

        for (int i = 0; i < cursor; i++) {

            count++;

            if (arr[i] > arr[i+1]) {
                T temp;
                temp = arr[i], arr[i] = arr[i+1], arr[i+1] = temp;
                modification = i;
            }
            
        }
        cursor = modification;
    }
    return count;
}

int main(){
    vector<int> v;
#ifndef _DEBUG
    v = getVector<int>(cin);
#else
    v.push_back(69); v.push_back(50); v.push_back(38);
#endif
    int count = bubbleSort<int>(v);
    cout << v << count;
    return 0;
}
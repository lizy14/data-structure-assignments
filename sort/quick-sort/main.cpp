/*
文件名: 
描　述: 数据结构习题10.30，非递归形式的快速排序

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015年12月11日

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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
void quickSort(vector<T>& arr) {
    
    
    struct Range {
        int a, b;
        Range(int a_=0, int b_=0):a(a_),b(b_){}
    };

    stack<Range> s; 

    int len = arr.size();
    s.push(Range(0, len - 1));

    while (!s.empty()) {
        Range range = s.top();
        s.pop();

        if(range.a >= range.b)
            continue;
        T mid = arr[range.b];
        int left = range.a, right = range.b - 1;
        while (left < right) {
            while (arr[left] < mid && left < right)
                left++;
            while (arr[right] >= mid && left < right)
                right--;
            std::swap(arr[left], arr[right]);
        }
        if (arr[left] >= arr[range.b])
            std::swap(arr[left], arr[range.b]);
        else
            left++;
        s.push(Range(range.a, left - 1));
        s.push(Range(left + 1, range.b));
    }
}

int main(){
    vector<int> v;
#ifndef _DEBUG
    v = getVector<int>(cin);
#else
    v.push_back(69); v.push_back(50); v.push_back(38);
#endif
    quickSort<int>(v);
    cout << v;
    return 0;
}
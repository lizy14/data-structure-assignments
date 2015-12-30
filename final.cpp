/*
文件名: 
描　述: 数据结构期末模拟试题 手写代码部分

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-30

环　境: x86_64-w64-mingw32-gcc-g++ 4.9.2
*/

#include <iostream>
#include <stack>
using namespace std;

/*
请将下列递归过程改为非递归过程。
*/
void test(int& sum){
    int x;
    cin >> x;
    if(x==0)
        sum = 0;
    else{
        test(sum);
        sum += x;
    }
    cout << sum << ' ';
}
void test_nonrecursive(int& sum){
    stack<int> s;
    int x;
    while(1){
        cin >> x;
        s.push(x);
        if(x==0){
            sum = 0;
            break;
        }
    }
    while(!s.empty()){
        sum += s.top();
        cout << sum << ' ';
        s.pop();
    }
}

/*
如果一个整数序列中有一半的数为奇数，一半的数为偶数。请编写一个算法，重新排
列这些整数，使所有奇数位于奇数下标，所有偶数位于偶数下标。注意：除了数据交
互单元外，算法不允许增加辅助数组。
*/
void sort(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i] % 2 == i % 2){
        }else{
            int j;
            for(j=i+1; j<n; j++){
                if(arr[j] % 2 == i % 2){
                    break;
                }
            }
            if(j==n)
                throw "error";
            int temp;
            temp=arr[j]; arr[j]=arr[i]; arr[i]=temp;
        }
    }
}

int main(){
    int sum;
    
    sum = 233;
    test(sum);
    cout << sum << endl;
    
    sum = 233;
    test_nonrecursive(sum);
    cout << sum << endl;
    
    return 0;
    
    int a[8] = {4,5,1,65,68,10,7,6};
    int n = sizeof(a)/sizeof(int);
    try{
        sort(a, n);
    }catch(const char* err){
        return cout << err, -1;
    }
    
    for(int i=0; i<n; i++)
            cout << a[i] << ' ';
    return 0;
}

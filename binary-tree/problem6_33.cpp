/*
文件名: 
描　述: 二叉树习题 6.33

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-29

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#include <iostream>

using namespace std;

int n;
int *L, *R;

void printBool(bool b){
	cout << (b?"true":"false");
}

//checks if u is a descendant of v
//to be called recursively
bool isDescendant(int u, int v){
	if(v==0)
		return false;
	if(u==v)
		return true;
	bool b = isDescendant(u, L[v]) || isDescendant(u, R[v]);
	return b;
}
int* getArray(int n){
	int *p = new int[n];
	for(int i=0; i<n; i++){
		cin >> p[i];
	}
	return p;
}
int main(int argc, char *argv[]){
	cin >> n;
	L = getArray(n+1);
	R = getArray(n+1);
	int u, v;
	cin >> u >> v;
	//end of input
	printBool(isDescendant(u, v));

	delete[] L;
	delete[] R;

	return 0;
}
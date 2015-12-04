/*
文件名: 
描述: Trie 树习题

作者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-04

环境: Visual Studio 2012 (MSVC++ 11.0)
*/
//#define LOCAL_DEBUG
#ifndef _DEBUG
#define nullptr NULL
#endif
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;
using std::cin;
using std::endl;
using std::cout;



struct TrieNode{
    typedef enum { Leaf, Branch } Type;
    Type type;
    string key;
    vector<TrieNode*> ptr; 
    int num;
    TrieNode(Type type_):type(type_){
        if(type == Branch)
            ptr.resize(27, nullptr);
        else
            ;
    }
    TrieNode(string word):type(Leaf), key(word){}
    void changeIntoBranch(){
        type = Branch;
        ptr.resize(27, nullptr);
    }
    operator string(){
        if(type == Leaf)
            return key;
        else{
            string ret = "(";
            bool comma = false;
            for(int i=0; i<ptr.size(); i++){
                if(ptr[i] != nullptr){
                    if(comma)
                        ret += ",";
                    comma = true;
                    ret += (string)(*ptr[i]);
                }
            }
            return ret += ")";
        }
    }
};

class TrieTree{
    TrieNode *root;
public:
    TrieTree():root(nullptr){
    }
    ~TrieTree(){
        //TODO
    }
    void insert(string word){
        if(!root){
            root = new TrieNode(word);
            return;
        }
        TrieNode *p = root, *q = p;

        int offset = 0; 
        //or you can call it depth in the tree

        //find where to insert
        while(1){
            if(p == nullptr){
                offset --;
                break;

            }
            if(p->type == p->Leaf)
                break;
            q = p;
            int index = word[offset] - 'A' + 1;
            p = p->ptr[index];
            offset ++;
        }


        if(p == nullptr){
            //just create a new leaf, done.
            TrieNode *newNode = new TrieNode(word);
            q->ptr[word[offset] - 'A' + 1] = newNode;
        }else if(p->type == p->Leaf){
            //clash! we have to create a new branch, as well as a new leaf.
            string oldWord = p->key;
            if(oldWord == word)
                return;
            p->changeIntoBranch();
            int newIndex, oldIndex;

            //go as deep as possible
            while(1){
                if(word.length() <= offset && offset < oldWord.length()){
                    p->changeIntoBranch();
                    p->ptr[0] = new TrieNode(word);
                    p->ptr[oldWord[offset]-'A'+1] = new TrieNode(oldWord);
                    return;
                }else if(oldWord.length()  <= offset && offset <  word.length()){
                    p->changeIntoBranch();
                    p->ptr[0] = new TrieNode(oldWord);
                    p->ptr[word[offset]-'A'+1] = new TrieNode(word);
                    return;
                }else{

                    newIndex = word[offset] - 'A' + 1;
                    oldIndex = oldWord[offset] - 'A' + 1;
                    if(newIndex != oldIndex)
                        break;
                    p->changeIntoBranch();
                    TrieNode *newNode = new TrieNode(p->Branch);
                    p->ptr[oldIndex] = newNode;
                    p = newNode;
                    offset ++;
                }

            }
            p->ptr[oldIndex] = new TrieNode(oldWord);
            p->ptr[newIndex] = new TrieNode(word);

        }

        return;
    }
    operator string(){
        return *root;
    }

};

int problem_9_42(){
#ifndef LOCAL_DEBUG
    TrieTree tree;

    string str;
    while(true){
        getline(cin, str);
        int comma;
        do{
            comma = str.find(',');
            tree.insert(str.substr(0, comma));
            str = str.substr(comma+1, -1);
        }while((comma != string::npos));
        break;
    }
    for(int i=0; i<3; i++){
        getline(cin, str);
        tree.insert(str);
    }


#endif
#ifdef LOCAL_DEBUG
    TrieTree tree;
    tree.insert("ZHAO");
    tree.insert("ZHANG");
    tree.insert("LI");
    tree.insert("LIN");
    tree.insert("LIU");
    cout << (string)tree;
    return system("pause");
#endif
    cout << (string)tree;
    return 0;
}

int main(){
    return problem_9_42();
}
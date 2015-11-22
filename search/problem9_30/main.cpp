/*
文件名: 
描　述: 数据结构习题9.30，双向循环链表上的顺序查找，带游标

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-20

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

typedef int ElemType;

//单向循环链表
struct CirLNode    
{
    ElemType data;
    struct CirLNode *next;
}; 
typedef CirLNode* CirLinkList;


//双向循环链表
struct DuLNode
{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
};
typedef DuLNode* DuLinkList;

DuLinkList createDuLinkListFromCirLinkList(CirLinkList list){
    if(!list)return NULL;
    DuLinkList newList = NULL;
    {
        DuLinkList q = newList;
        DuLNode *newNode;
        CirLNode *p = list;
        do{
            newNode = (DuLinkList)malloc(sizeof(DuLNode));
            if(q==NULL){
                newList = q = newNode;
                newNode->data = p->data;
                newNode->next = NULL;
            }else{
                q->next = newNode;
                q = newNode;
                q->data = p->data;
                q->next = NULL;
            }
            p = p->next;
        }while(p!=list);
        q->next = newList;
    }
    //creation of newList finished. now it is a copy of list. then comes the core part

    DuLinkList p=newList->next;
    DuLinkList q = newList;
    do{
        p->prior = q;
        q = q->next;
        p = p->next;
    }while(p!=newList->next);

    return newList;
}

CirLinkList makeIntegerCircularList(int n){
    CirLinkList head;
    
    if(n==0){
        return NULL;
    }else{
        head = (CirLinkList)malloc(sizeof(CirLNode));
        if(!head){
            //TODO: handle failure of malloc()
            return NULL;
        }
    }
    CirLinkList p = head;
    int i;
    int _;
    CirLinkList node;
    for(i=0; i<n; i++){
        cin >> _;
        if(i==0){
            node = head;
            node->data = _;
            node->next=NULL;
        }
        else{
            node = (CirLinkList)malloc(sizeof(CirLNode));
            if(!node){
                //TODO: handle failure of malloc()
                return NULL;
            }
            node->data = _;
            node->next = NULL;
            p->next = node;
            p = p->next;
        }


    }
    p->next = head;
    return head;
}


int main(int argc, char *argv[]){
    
    int _1, _2;
    cin >> _1 >> _2;
    
    DuLinkList list = 
        createDuLinkListFromCirLinkList(makeIntegerCircularList(_1));
    
    vector<int> queries;
    for(int i=0; i<_2; i++){
        int _;
        cin >> _;
        queries.push_back(_);
    }
    DuLNode *sp = list;
    for(int i=0; i<_2; i++){
        int _ = queries[i];
        int nComparisons = 0;
        if(_ == sp->data){
            cout << "1 0\n";
        }else if(_ > sp->data){
            while(233){
                nComparisons ++;
                if(_ < sp->data){
                    cout << "0 " << nComparisons << '\n';
                    break;
                }
                if(_ == sp->data){
                    cout << "1 " << nComparisons << '\n';
                    break;
                }
                if(sp->next < sp){
                    //reaches the end of list
                    cout << "0 " << nComparisons << '\n';
                    break;
                }
                sp = sp->next;
            }
        }else if(_ < sp->data){
            while(233){
                nComparisons ++;
                if(_ > sp->data){
                    cout << "0 " << nComparisons << '\n';
                    break;
                }
                if(_ == sp->data){
                    cout << "1 " << nComparisons << '\n';
                    break;
                }
                if(sp->prior > sp){
                    //reaches the start of list
                    cout << "0 " << nComparisons << '\n';
                    break;
                }
                sp = sp->prior;
            }
        }
    }
    
    return 0;
}
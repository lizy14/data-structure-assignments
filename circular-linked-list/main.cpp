#define LOCAL_DEBUG

/*
文件名: 
描　述: 循环链表习题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-10

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef char ElemType; //char or int


//双向循环链表
struct DuLNode
{
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
};
typedef DuLNode* DuLinkList;


//单链表
struct LNode    
{
	ElemType data;
	struct LNode *next;
};
typedef LNode* LinkList;


//单向循环链表
struct CirLNode    
{
	ElemType data;
	struct CirLNode *next;
}; 
typedef CirLNode* CirLinkList;


//I/O operations

//input
//2-33, from link-list, unmodified
LinkList makeCharListFromStdin(){
	LinkList head;
	int n=0;
	scanf("\n%d\n", &n);
	if(n==0){
		return NULL;
	}else{
		head = (LinkList)malloc(sizeof(LNode));
		if(!head){
			//TODO: handle failure of malloc()
			return NULL;
		}
	}
	LinkList p = head;
	int i;
	char _;
	LinkList node;
	for(i=0; i<n; i++){
		if(i==n-1)
			scanf("%c", &_);
		else
			scanf("%c ", &_);
		if(i==0){
			node = head;
			node->data = _;
			node->next=NULL;
		}
		else{
			node = (LinkList)malloc(sizeof(LNode));
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
	return head;
}
//2-31, 32
CirLinkList makeIntegerCircularListFromStdin(){
	CirLinkList head;
	int n=0;
	scanf("\n%d\n", &n);
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
		scanf("%d", &_);
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

//output
//2-31, 33
#define DATA_TYPE_INT 1
#define DATA_TYPE_CHAR 2
void printCircularList(CirLinkList list, int dataType){
	if(!list)
		return;
	CirLinkList p = list;
	do{
		printf(dataType==DATA_TYPE_INT?"%d ":"%c ",p->data);
		p = p->next;
	}while(p!=list);
}
//2-32
#define ORDER_NORMAL 1
#define ORDER_INVERTED 2
void printIntegerDuLinkList(DuLinkList list, int order){
	if(!list)
		return;
	DuLinkList p = list;
	do{
		printf("%d ",p->data);
		if(order == ORDER_NORMAL)
			p = p->next;
		else
			p = p->prior;
	}while(p!=list);
}

//end of I/O operations



//2-31
void removePriorInCirLinkList(CirLinkList list){
	//TODO: do something
	return;
}
CirLNode* findElementInCirLinkList(ElemType elem, CirLinkList list){
	CirLinkList p = list;
	do{
		if(p->data == elem)
			return p;
		p = p->next;
	}while(p != list);
	return NULL;
}

//2-32
DuLNode* findElementInDuLinkList(ElemType elem, DuLinkList list){
	DuLinkList p = list;
	do{
		if(p->data == elem)
			return p;
		p = p->next;
	}while(p != list);
	return NULL;
}
DuLinkList createDuLinkListFromCirLinkList(CirLinkList list){
	//TODO: do something
	return NULL;
}

//2-33
void createMultipleCirLinkListsFromLinkList(LinkList list, CirLinkList listA, CirLinkList list1, CirLinkList list_){
	//TODO: do something
	return;
}

void problem2_31(){
	CirLinkList list = makeIntegerCircularListFromStdin();
	CirLinkList inCaseHeadIsRemoved = list?list->next:NULL;
	int elem;
	scanf("%d", &elem);
	removePriorInCirLinkList(findElementInCirLinkList(elem, list));
	if(list)
		printCircularList(list, DATA_TYPE_INT);
	else
		printCircularList(inCaseHeadIsRemoved, DATA_TYPE_INT);
	return;
}
void problem2_32(){
	CirLinkList cirLinkList = makeIntegerCircularListFromStdin();
	DuLinkList duLinkList = createDuLinkListFromCirLinkList(cirLinkList);
	int elem;
	scanf("%d", &elem);
	printIntegerDuLinkList(findElementInDuLinkList(elem, duLinkList), ORDER_INVERTED);
	return;
}
void problem2_33(){
	LinkList list = makeCharListFromStdin();
	CirLinkList listA=NULL, list1=NULL, list_=NULL;
	createMultipleCirLinkListsFromLinkList(list, listA, list1, list_);
	printCircularList(listA, DATA_TYPE_CHAR);
	putchar('\n');
	printCircularList(list1, DATA_TYPE_CHAR);
	putchar('\n');
	printCircularList(list_, DATA_TYPE_CHAR);
	putchar('\n');
	return;
}
void test(){
	CirLinkList list = makeIntegerCircularListFromStdin();
	printCircularList(findElementInCirLinkList(50, list), DATA_TYPE_INT);
	return;
}
int main(){
	test();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

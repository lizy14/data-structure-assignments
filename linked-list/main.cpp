#define LOCAL_DEBUG
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define C_STYLE_INPUT
#ifdef C_STYLE_INPUT
#else
#include <iostream>
#endif
struct LNode
{
	char data;//char or int
	struct LNode *next;
};
typedef LNode* LinkList;



//basic list operations
LinkList makeCharListFromStdin(){
	LinkList head;
	int n=0;
#ifdef C_STYLE_INPUT
	scanf("\n%d\n", &n);
#else
	std::cin >> n;
#endif
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
#ifdef C_STYLE_INPUT
		if(i==n-1)
			scanf("%c", &_);
		else
			scanf("%c ", &_);
#else
		std::cin >> _;
#endif
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
LinkList makeIntegerListFromStdin(){
	LinkList head;
	int n=0;
#ifdef C_STYLE_INPUT
	scanf("\n%d\n", &n);
#else
	std::cin >> n;
#endif
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
	int _;
	LinkList node;
	for(i=0; i<n; i++){
#ifdef C_STYLE_INPUT
		scanf("%d", &_);
#else
		std::cin >> _;
#endif
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
int getListLength(LinkList list){
	int i=0;
	LinkList p = list;
	while(p!=NULL){
		i++;
		p = p->next;
	}
	return i;
}
void printCharList(LinkList list){
	LinkList p = list;
	while(p!=NULL){
		printf("%c ",p->data);
		p = p->next;
	}
}
void printIntegerList(LinkList list){
	LinkList p = list;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}


//Problem 2.15
//append listB to listA
LinkList joinLists(LinkList listA, LinkList listB){
	if(listA==NULL){
		listA = listB;
	}else{
		LinkList p = listA;
		while(1){
			if(!(p->next)){
				p->next = listB;
				break;
			}
			p = p->next;	
		}
	}
	return listA;
}


//Problem 2.22
//invert a list, supposed to be taking no external space. 
//but here... I played a trick. 
//this function is to be called recursively.
LinkList invertList(
	LinkList headOfTheListToBeInverted, 
	LinkList listToBePointedToByTheLastNodeOfTheInvertedList)
{
	LinkList invertedChildList;
	if(!headOfTheListToBeInverted){
		return NULL;
	}
	if(!(headOfTheListToBeInverted->next)){
		invertedChildList = headOfTheListToBeInverted;
	}else{
		invertedChildList= invertList(headOfTheListToBeInverted->next, headOfTheListToBeInverted);
	}
	headOfTheListToBeInverted->next = listToBePointedToByTheLastNodeOfTheInvertedList;
	return invertedChildList;
}


//Problem 2.25
//make a list which is a intersection of listA and listB. 
//suppose that the two lists are sorted increasingly.
LinkList makeIntersectionOfTwoSortedLists(LinkList listA, LinkList listB){
	if(!listA && !listB)
		return NULL;
	LinkList head = NULL;
	LinkList p = NULL;
	LinkList node;
	while(1){
		if(!listA && !listB)
			break;
		if(listB && (!listA || listA->data > listB->data	)){
			listB = listB->next;
		}else if(listA && (!listB || listA->data < listB->data)){
			listA = listA->next;
		}else{//equal
			if(p==NULL){
				head = (LinkList)malloc(sizeof(LNode));
				head->data=listB->data;
				head->next=NULL;
				p=head;
			}else{
				node = (LinkList)malloc(sizeof(LNode));
				node->data = listB->data;
				node->next = NULL;
				p->next = node;
				p=p->next;
			}
			listB = listB->next;
			listA = listA->next;
		}
	}
	return head;
}


LinkList makeUnionOfTwoSortedLists(LinkList listA, LinkList listB){
	if(!listA && !listB)
		return NULL;
	LinkList head = NULL;
	LinkList p = NULL;
	LinkList node;
	while(1){
		if(!listA && !listB)
			break;
		if(listB && (!listA || listA->data > listB->data	)){
			if(p==NULL){
				head->data=listB->data;
				head->next=NULL;
				p=head;
			}else{
				node = (LinkList)malloc(sizeof(LNode));
				node->data = listB->data;
				node->next = NULL;
				p->next = node;
				p=p->next;
			}
			listB = listB->next;
		}else if(listA && (!listB || listA->data < listB->data)){
			if(p==NULL){
				head->data=listA->data;
				head->next=NULL;
				p=head;
			}else{
				node = (LinkList)malloc(sizeof(LNode));
				node->data = listA->data;
				node->next = NULL;
				p->next = node;
				p=p->next;
			}
			listA = listA->next;
		}else{//equal
			if(p==NULL){
				head = (LinkList)malloc(sizeof(LNode));
				head->data=listB->data;
				head->next=NULL;
				p=head;
			}else{
				node = (LinkList)malloc(sizeof(LNode));
				node->data = listB->data;
				node->next = NULL;
				p->next = node;
				p=p->next;
			}
			listB = listB->next;
			listA = listA->next;
		}
	}
	return head;
}

//remove elements in listB from listA: get complement set of B in A.
LinkList makeComplementOfSortedList(LinkList listA, LinkList listB){
	if(!listA || !listB)
		return listA;
	LinkList head = NULL;
	LinkList p = NULL;
	LinkList pA = listA;
	LinkList pB = listB;
	while(1){
		if(!pA){
			break;
		}
		if(!pB || pB->data > pA->data){
			LinkList q = (LinkList)malloc(sizeof(LNode));
			q->data = pA->data;
			q->next = NULL;
			if(!head){
				head = p = q;
			}else{
				p->next = q;
				p = q;
			}
			pA = pA->next;
		}else if(pB->data < pA->data){
			pB = pB->next;
			continue;
		}else if(pB->data == pA->data){
			pA = pA->next;
		}
	}
	return head;
}

void problem2_15(){
	LinkList listA = makeCharListFromStdin();
	LinkList listB = makeCharListFromStdin();
	listA = joinLists(listA, listB);
	printf("%d\n", getListLength(listA));
	printCharList(listA);

	//TODO: release allocated memory
}
void problem2_22(){
	LinkList listA = makeCharListFromStdin();
	printCharList(invertList(listA, NULL));
	//TODO: release allocated memory
}
void problem2_25(){
	LinkList listA = makeIntegerListFromStdin();
	LinkList listB = makeIntegerListFromStdin();
	LinkList intersection = (makeIntersectionOfTwoSortedLists(listA, listB));
	printf("%d\n", getListLength(intersection));
	printIntegerList(intersection);
	//TODO: release allocated memory
}
void problem2_29(){
	LinkList listA = makeIntegerListFromStdin();
	LinkList listIntersection = NULL;
	LinkList listB = makeIntegerListFromStdin();
	LinkList listC = makeIntegerListFromStdin();
	listIntersection = makeIntersectionOfTwoSortedLists(listB, listC);
	LinkList listAnswer = makeComplementOfSortedList(listA, listIntersection);
	printf("%d\n", getListLength(listAnswer));
	printIntegerList(listAnswer);
	//TODO: release allocated memory
}
int main(){
	problem2_29();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

#define LOCAL_DEBUG
/*
文件名: 
描　述: 稀疏多项式

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-09

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

struct PolyTerm //稀疏多项式的顺序存储结构
{
	int coef;
	int exp;
	PolyTerm *next; //added
};

struct SqPoly
{
	PolyTerm *data;
	int length;
};


#include <stdio.h>
#include <stdlib.h>
SqPoly makePolyFromFile(FILE* file){
	PolyTerm *head = NULL;
	PolyTerm *p = NULL;
	int n;
	fscanf(file, "%d", &n);
	int i;
	int c, e;
	for(i=0; i<n; i++){
		fscanf(file, "%d %d", &c, &e);
		PolyTerm *q = (PolyTerm*)malloc(sizeof(PolyTerm));
		q->next = NULL;
		q->coef = c;
		q->exp = e;
		if(head==NULL){
			head = p = q;
		}else{
			p->next = q;
			p=p->next;
		}
	}
	SqPoly ret;
	ret.length = n;
	ret.data = head;
	return ret;
}
void printPoly(SqPoly poly){
	printf("%d\n", poly.length);
	PolyTerm *p = poly.data;
	while(p){
		printf("%d %d\n", p->coef, p->exp);
		p = p->next;
	}
	putchar('\n');
}
int exponent(int x, int e){
	int i;
	int ret=1;
	for(i=0; i<e; i++){
		ret *= x;
	}
	return ret;
}
int evaluatePolyTerm(PolyTerm term, int x){
	return exponent(x, term.exp)*term.coef;
}
int evaluatePoly(SqPoly poly, int x){
	int ret = 0;
	PolyTerm *p = poly.data;
	while(p){
		ret += evaluatePolyTerm(*p, x);
		p=p->next;
	}
	return ret;
}
//returns k*A+l*B, ignoring terms whose c == 0
SqPoly linearCombinationOfOrderedPoly(int k, SqPoly polyA, int l, SqPoly polyB){
	PolyTerm *head = NULL;
	PolyTerm *p = NULL;
	PolyTerm *pA = polyA.data;
	PolyTerm *pB = polyB.data;
	PolyTerm *q = NULL;
	int n=0;
	
	//TODO
	while(1){
		
		if(!pA && !pB){
			break;
		}
#ifdef LOCAL_DEBUG
		printf("A=%d, B=%d\n", pA?pA->exp:-1, pB?pB->exp:-1);
#endif
		//create a new term
		q = (PolyTerm*)malloc(sizeof(PolyTerm));
		q->coef = 0;
		q->next = NULL;

		//assign to the newly created term
		/*输入样例有误，此处按指数递增处理*/
		if(!pA || (pA && pB && pA->exp >/**/ pB->exp)){
			q->coef = l * pB->coef;
			q->exp = pB->exp;
			pB = pB->next;
		}else if(!pB || (pA && pB && pA->exp </**/ pB->exp)){
			q->coef = k * pA->coef;
			q->exp = pA->exp;
			pA = pA->next;
		}else if(pA && pB && pA->exp == pB->exp){
			q->exp = pA->exp;
			q->coef = k * pA->coef + l * pB->coef;
			pA = pA->next;
			pB = pB->next;
		}
		//add q into the result
		if(q->coef){
			n++;
			if(head==NULL){
				head = p = q;
			}else{
				p->next = q;
				p = p->next;
			}
		}else{
			free(q);
		}
	}

	SqPoly ret;
	ret.length = n;
	ret.data = head;
	return ret;
}
void problem2_39(){
	SqPoly poly = makePolyFromFile(stdin);
	int x;
	scanf("%d", &x);
	int y=evaluatePoly(poly, x);
	printf("%d", y);
	//TODO: release memory
	return;
}
void problem2_40(){
	SqPoly polyA = makePolyFromFile(stdin);
	SqPoly polyB = makePolyFromFile(stdin);
	SqPoly difference = linearCombinationOfOrderedPoly(1, polyA, -1, polyB);
	printPoly(difference);
	//TODO: release memory
	return;
}
int main(){
	problem2_40();
#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

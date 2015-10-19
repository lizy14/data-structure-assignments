#define LOCAL_DEBUG
/*
文件名: 
描　述: 栈和队列习题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-10-11

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#include <stack>
#include <queue>
#include <string>
#include <iostream>

//以循环链表实现的队列
template <class T> class QueueItem{
public:
	T data;
	QueueItem<T> *prev, *next;
public:
	QueueItem(T data_): prev(NULL), next(NULL), data(data_){}
};
template <class T> class Queue{
	QueueItem<T> *tail;
public:
	Queue():tail(NULL){}
	~Queue(){
		if(!tail)
			return;
		QueueItem<T> *p = tail, *q;
		do{
			q = p;
			p = p->next;
			delete q;
		}while(p != tail);
	}
	void pop(){
		QueueItem<T> 
			*head = tail->next;
		tail->next = head->next;
		head->next->prev = tail;
		delete head;
		if(head==tail)
			tail = NULL;
	}
	void push(T item){
		QueueItem<T> 
			*q = new QueueItem<T>(item);
		if(!tail){
			tail = q;
			tail->prev = tail->next = tail;
			return;
		}
		QueueItem<T> *head = tail->next;
		q->prev = tail;
		q->next = head;
		tail->next = q;
		head->prev = q;
		tail = q;
	}
	T front(){
		if(!tail)
			throw "Queue is empty";
		return tail->next->data;
	}
	T back(){
		if(!tail)
			throw "Queue is empty";
		return tail->data;
	}
	bool empty(){
		return (tail == NULL);
	}
	//aliases
	T dequeue(){T item=front(); pop(); return item;}
	void enqueue(const T item){push(item);}
};


//以数组实现的循环队列
//所用数组长度比队列容量多 1
template<class T>
class CyclicQueue
{ 
	T *data;
	int rear;
	int front_;
	static const int MAX_CAPACITY = 128;
	int k;
public:
	CyclicQueue(int capacity = MAX_CAPACITY){
		k = capacity+1;
		data = new T[k];
		front_ = rear = 0;
	}
	~CyclicQueue(){
		delete[] data;
	}
	
	//求队列中各项之和
	int sum(){
		int sum_=0;
		int i=front_;
		while(i != rear){
			sum_ += data[i];
			i++;
			i%=k;
		}
		return sum_;
	}
	bool empty(){
		return front_==rear;
	}
	void push(const T item){
		if((rear+1)%k == front_)
			throw "Queue is full";
		data[rear] = item;
		rear+=1; 
		rear%=k;
	}
	T front(){
		if(empty())
			throw "Queue is empty";
		return data[front_];
	}
	void pop(){
		if(empty())
			throw "Queue is empty";
		front_+=1; 
		front_%=k;
	}
	//aliases
	T dequeue(){T item=front(); pop(); return item;}
	void enqueue(const T item){push(item);}

};
template <class Q>
void dumpQueue(Q q){
	while(!q.empty())
		std::cout << q.dequeue() << ' ';
}
//checks if a string is a palindrome
bool isPalindrome(
	std::istream& stream,
	const char endOfInput = EOF)
{
	std::stack<char> stack;
	std::queue<char> queue;
	char chr;
	while(1){
		stream >> chr;
		if(chr == endOfInput)
			break;
		stack.push(chr);
		queue.push(chr);
	}
	while(1){
		if(stack.empty() && queue.empty())
			return true;
		if(stack.empty() || queue.empty())
			return false;
		if(stack.top() != queue.front())
			return false;
		
		stack.pop();
		queue.pop();
	}
}
void printBool(bool b){
	std::cout << (b? "true": "false") << std::endl;
}

void problem3_28(){
	Queue<int> queue;
	
	int _, __;
	std::string ___;

	std::cin >> _;
	for(int i=0; i<_; i++){
		std::cin >> __;
		queue.push(__);
	}

	std::cin >> _;
	for(int i=0; i<_; i++){
		std::cin >> ___;
		if(___ == "delete")
			queue.pop();
		else if(___ == "insert"){
			std::cin >> __;
			queue.push(__);
		}
	}

	while(!queue.empty()){
		std::cout << queue.front() << ' ';
		queue.pop();
	}
}
void problem3_31(){
	bool answer = isPalindrome(std::cin, '@');
	printBool(answer);
}
void test(){
	//Queue<int> queue;
	CyclicQueue<int> queue(10);
	queue.push(10);
	queue.push(12);
	queue.push(13);
	dumpQueue(queue);
}
void problem3_32(){
	
	int k, max;
	//std::cin >> k >> max
	k=3, max=242;
	CyclicQueue<int> queue(k);

	int sum = 1;
	queue.enqueue(1);
	for(int i=2; i<=k; i++){
		//enqueues f(2) to f(k)
		int newItem = queue.sum();
		if(newItem > max){
			dumpQueue(queue);
			return;
		}
		queue.enqueue(newItem);
	}
	while(1){
		int newItem = queue.sum();
		if(newItem > max){
			dumpQueue(queue);
			return;
		}
		queue.dequeue();
		queue.enqueue(newItem);
	}

}
int main(){
	problem3_32();
	
#ifdef LOCAL_DEBUG
	system("pause");
#endif
	return 0;
}

/*
文件名: 
描　述: 哈希表习题

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-04

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <string>
#include <vector>
#include <iostream>
using std::vector;
using std::string;
using std::cin;
using std::endl;
using std::cout;


template<class T>
class ListItem{
public:
    T data;
    ListItem<T> *prev;
    ListItem<T> *next;
    ListItem():next(nullptr),prev(nullptr){}
};

template<class T>
class List{
public:
    ListItem<T> *head;
    ListItem<T> *tail;
    int length;
public:
    List():
        head(nullptr),tail(nullptr),length(0),
        lastQueryPointer(nullptr){}
    ~List(){
        ListItem<T> *p = head, *q;
        while(p!=nullptr){
            q = p;
            p = p->next;
            delete q;
        }
    }
    List(List& old):
        head(nullptr),tail(nullptr),length(0),
        lastQueryPointer(nullptr){
            ListItem<T> *p = old.head;
            while(p!=nullptr){
                push(p->data);
                p = p->next;
            }
    }
    void push(T item){
        length++;
        ListItem<T> *p = new ListItem<T>();
        p->data = item;
        if(tail==nullptr){
            tail = head = p;
        }else{
            tail->next = p;
            p->prev = tail;
            tail = p;
        }
    }
    bool empty(){
        return (head==nullptr);
    }
    int lastQueryIndex;
    ListItem<T> *lastQueryPointer;
    T& operator[](int index){
        //保存上一次下标查询的结果
        //这样一来，使用下标遍历链表只需线性时间
        int i;
        ListItem<T> *p;
        if(lastQueryPointer!=nullptr){
            i=lastQueryIndex;
            p=lastQueryPointer;
        }else{
            i=0;
            p=head;
        }
        do{
            if(i == index){
                lastQueryIndex = i;
                lastQueryPointer = p;
                return p->data;
            }
            if(i<index){
                i++;
                p=p->next;
            }else{
                i--;
                p=p->prev;
            }

        }while(p != nullptr);
        throw "Index out of range";
    }
    T* find(T t){
        lastQueryPointer = nullptr;
        for(int i=0; i<length; i++){
            if(operator[](i) == t)
                return &(operator[](i));
        }
        return nullptr;
    }

};


template<class KeyType, class ValueType>
class HashTable{
public:
    int count;


    HashTable():count(0){}

    struct Pair{
        KeyType key;
        ValueType value;
        Pair(KeyType k, ValueType v):key(k),value(v){}
        Pair(){}
        bool operator==(Pair x){
            return key == x.key;
        }
    };



    vector<List<Pair> > v;

    void insert(KeyType key, ValueType value){
        int addr = hash(key);
        if(addr >= v.size())
            v.resize(addr+1);
        count ++;
        v[hash(key)].push(Pair(key, value));
    }

    ValueType operator[](KeyType key){
        Pair *p;
        if(hash(key) >= v.size())
            throw("not found");
        p = v[hash(key)].find(Pair(key, 0));

        if(!p)
            throw("not found");
        return p->value;
    }
};

int hash(string str){
    return (char)str[0] - 'A';
}

struct Position{
    int x, y;
    Position(int x_, int y_):x(x_), y(y_){}
    Position(){}
    bool operator==(Position z){
        return z.x == x && z.y == y;
    }

};

int hash(Position p){
    return p.x + p.y;
}
int problem_9_44(){
    int n;
    cin >> n;

    vector<vector<string> > table;
    table.resize(26);

    string word;
    getline(cin, word);

    for(int i=0; i<n; i++){
        getline(cin, word);
        table[hash(word)].push_back(word);
    }

    for(int i=0; i<table.size(); i++){
        for(int j=0; j<table[i].size(); j++){
            cout << table[i][j] << endl;
        }
    }

    return 0;

}
int problem_9_46(){

    int n, x_, y_, z;
    HashTable<Position, int> table;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x_ >> y_ >> z;
        table.insert(Position(x_, y_), z);
    }
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x_ >> y_;
        try{
            cout << table[Position(x_, y_)] << endl;
        }catch(...){
            cout << 0 << endl;
        }

    }
    return 0;
}

int main(){
    return problem_9_46();
}
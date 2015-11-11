# 习题9.27
时间限制:1s

内存限制:128M

【题目描述】 试改写教科书9.1.2节中折半查找的算法，当r[i].key≤K≤r[i+1].key(i=1,2,...,n-1)时，返回i；当K≤kr[1].key时，返回0；当K≥r[n].key时，返回n.

建议使用如下数据结构

    typedef int KeyType;

    typedef struct{
    　　KeyType key;
    　　DataType data;
    }ElemType;

    typedef struct{
    　　ElemType *elem;
    　　int length;
    }SSTable;

说明：本题中并未用到data变量

输入格式共三行,第一行只有一个数字n,表示数字个数。

第二行共有n个空格隔开的数字，保证数字按递增顺序排序。第三行为待查找数值K。

输出格式共1行，输出查找结果。

输入格式

    4
    1 3 4 5
    3
    
输出格式

    2
    
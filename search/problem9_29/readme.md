# 习题9.29
时间限制:1s

内存限制:128M

按照习题集9.29的方法修改有序表查询算法。若查找成功，则输出查询结果序号，失败则输出0。

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

输入格式共四行,第一行只有一个数字n,表示数字个数。

第二行共有n个空格隔开的数字，保证数字按递增顺序排序。第三,第四行分别为待查找数量m与m个查询。

输出格式共1行，输出查找结果。

输入格式

    4
    1 3 4 5
    3
    1
    5
    0
    
输出格式

    1
    4
    0
    
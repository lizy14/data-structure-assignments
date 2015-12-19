# 习题10.34

时间限制:1s

内存限制:128M

编写堆排序时，实现插入新数据方法。已有了p个元素的堆，能够以O(log n)算法复杂度添加第p+1个元素。

    #define MAXSIZE 200 //最大长度

    typedef int KeyType;
    typedef int InfoType;

    typedef struct {
        KeyType key;
        InfoType otherinfo;
    }RcdType;

    typedef struct {
        RcdType r[MAXSIZE + 1]; //r[0]闲置或者用作哨兵单元
        int length;
    }SqList;
    
输入格式第一行为一个待排序数字总个数n。第二行共有随机n个数字。第三行为要增加的数字k。

输出共一行，输出排序后的结果。

输入格式

    2
    69 50
    38

输出格式

    38 50 69

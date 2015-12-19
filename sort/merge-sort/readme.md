# 习题10.36

时间限制:1s

内存限制:128M

假设序列中有k个长度为 <=l 的有序子序列。利用过程merge对它们进行两两归并，得到┌ k/2 ┐个长度<=2l 的有序子序列，称为一趟归并排序。 反复调用一趟归并排序过程，使有序子序列的长度自l = 1开始成倍增加，直到整个序列成为一个有序序列。 使用递推算法实现，而不要使用递归。

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
    
输入格式第一行为一个待排序数字总个数n。第二行共有随机n个数字。

输出共一行，输出排序后的结果。

输入格式

    3
    69 50 38
    
输出格式

    38 50 69

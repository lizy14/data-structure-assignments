# 习题10.35

时间限制:1s

内存限制:128M

编写基于完全三叉树的堆排序算法。定位堆为满足以下特性的完全三叉树：（1）空树为堆。（2）根结点的值不小于所有子树根的值，且所有子树均为堆。排序时，不许自行设立其他数组等。

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

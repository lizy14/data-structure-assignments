# 习题10.26

时间限制:1s

内存限制:128M

修改起泡算法.将（课本1.4.3节算法）原本用来记录“此次冒泡是否进行过交换”的布尔变量change改为整数变量，提示每一趟排序中经过交换的最后一个记录的位置，并以它作为下一趟起泡排序循环的终止控制量。

建议使用如下数据结构

    #define MAXSIZE 200 //最大长度

    typedef int KeyType;
    typedef int InfoType;

    typedef struct {
        KeyType key;
    }RcdType;

    typedef struct {
        RcdType r[MAXSIZE + 1]; //r[0]闲置或者用作哨兵单元
        int length;
    }SqList;

输入格式第一行为一个待排序数字总个数n。第二行共有随机n个数字。

输出共两行，第一行为排序后的结果，第二行为“此次冒泡是否进行过交换”的最少次数。

输入格式

    3
    69 50 38

输出格式

    38 50 69
    3

    
    
    
# 习题10.28

时间限制:1s

内存限制:128M

编写双向起泡算法。双向起泡即同时向两个方向起泡，一次循环找出未排序部分的最大值、最小值。请避免将算法写成两个并在一起的相似的单向起泡算法段。

建议使用如下数据结构

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

# 习题2.32
时间限制:1s

内存限制:128M

已知有一个单向循环链表，其每个结点中含三个域：prior,data和next,其中data域为数据域，next为指向后继结点的指针域,prior也为指针域,但它的值为空(NULL),试编写算法将此单向循环链表改为双向循环链表，即使prior成为指向前驱结点的指针域。

建议使用如下数据结构完成。也可自行实现该数据结构。

    struct DuLNode
    {
        ElemType data;
        struct DuLNode *prior;
        struct DuLNode *next;
    };

    typedef DuLNode* DuLinkList;

输入格式分为三行，第一行为该单向循环链表的长度，第二行为单向循环链表的各元素，用数字表示（各不相同）。 第三行为一个数字n，要求输出时一该元素为起点反向输出。

输出格式为一行，即完成双向链表后以反向顺序输出该链表。

输入格式

    5
    1 2 3 4 6
    1

输出格式

    1 6 4 3 2

# 习题2.33
时间限制:1s

内存限制:128M

已知由一个线性链表表示的线性表中含有三类字符的数据元素(如：字母元素、数字元素和任意字符)。试编写算法将该线性链表分割为三个循环链表，其中每个循环链表表示的线性表中均只含一类字符。

建议使用如下数据结构完成。也可自行实现该数据结构。

    typedef char ElemType;

    struct LNode    //单链表
    {
        ElemType data;
        struct LNode *next;
    };

    typedef LNode* LinkList;

    struct CirLNode    //单向循环链表
    {
        ElemType data;
        struct CirLNode *next;
    }; 

    typedef CirLNode* CirLinkList;

输入格式第一行为数字n,表示线性表共有n个节点。接下来共有1行，3*n个元素，以空格隔开，分别表示三种类型的元素。每三个依次为字母，数字，随机字符。

输出格式为三行，每行依次输出三种类型的循环链表中的元素。顺序与输入相同，以空格隔开。

输入格式

    3
    A 1 f B 3 * E 6 0

输出格式

    A B E
    1 3 6
    f * 0

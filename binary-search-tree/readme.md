# 习题9.34
时间限制:1s

内存限制:128M

试写一时间复杂度为O(log2(n)+m)的算法，删除二叉排序树中所有关键字不小于x的结点，并释放结点空间。其中n为树中所含结点数，m为被删除的结点个数。注意：二叉树有可能为空。

建议使用如下数据结构

    typedef int KeyType;

    typedef struct BiTNode{
    　　KeyType key;
    　　struct BiTNode *lchild, *rchild;
    }BiTNode, *BiTree;
    
输入格式共两行,第一行为待操作二叉排序树的广义表达。

第二行为待删除数值x。

输出格式共一行，为删除节点后的二叉排序树。

输入格式

    2(1,3(-,4))
    3
    
输出格式

    2(1,-)
    
样例输入输出说明:

此处用广义表表示二叉树，根的左子树在前，右子树在后，若左右子树中有一个为空，则用'-'代替之。若输出树为空，则输出应也为空。


# 习题9.36
时间限制:1s

内存限制:128M

在以带头结点的二叉线索链表为存储结构的二叉排序树上实现插入一个关键字的操作。

建议使用如下数据结构

    typedef int KeyType;

    typedef enum PointerTag {Link, Thread};

    typedef struct BiThrNode{
    　　KeyType key;
    　　struct BiThrNode *lchild, *rchild;
    　　PointerTag LTag, RTag;
    }BiThrNode, *BiThrTree;
    
输入格式共两行,第一行为待操作二叉排序树的广义表达。

第二行为待插入数值x。

输出格式共一行，为插入节点后的二叉排序树。

输入格式

    5(2,8)
    3

输出格式

    5(2(-,3),8)

样例输入输出说明:

此处用广义表表示二叉树，根的左子树在前，右子树在后，若左右子树中有一个为空，则用'-'代替之。若输出树为空，则输出应也为空。



# 习题9.39
时间限制:1s

内存限制:128M

试写一个算法，将一个二叉排序树，分裂为两棵二叉排序树，使得其中一棵的所有节点的关键字都小于或等于x,另一棵树的任意节点关键字都大于x。

建议使用如下数据结构

    typedef int KeyType;

    typedef enum PointerTag {Link, Thread};

    typedef struct BiThrNode{
    　　KeyType key;
    　　struct BiThrNode *lchild, *rchild;
    　　PointerTag LTag, RTag;
    }BiThrNode, *BiThrTree;

输入格式共两行,第一行为待操作二叉排序树的广义表达。

第二行为数值x。

输出格式共两行，为分裂后的二叉排序树。要求关键字较小的先输出。

输入格式

    5(2,8)
    3

输出格式

    2
    5(－,8)

样例输入输出说明:

此处用广义表表示二叉树，根的左子树在前，右子树在后，若左右子树中有一个为空，则用'-'代替之。若输出树为空，则输出应也为空。
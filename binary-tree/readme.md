# 习题6.33
时间限制:1s

内存限制:128M

假定两个一维数组L[n+1]和R[n+1]作为有n个结点的二叉树的存储结构，L[i]和R[i]分别指示结点i的左孩子右孩子，0表示空，试写一个算法判别结点u是否为结点v的子孙

输入格式共四行，第一行只有一个数字n，表示二叉树的节点个数。第二第三行分别由n+1个元素，分别为L[n+1]与R[n+1]的元素。

第四行有两个数字,u,v,要求判断u是否为v的子孙结点。（u,v可能相同，相同时输出为true）

输出格式共一行，u是v的子孙结点则输出true，否则输出false。
输入格式

    3
    0 2 0 0
    0 3 0 0
    2 1

输出格式

    true

    
# 习题6.45
时间限制:1s

内存限制:128M

编写递归算法，对于二叉树中每一个元素值data等于x的节点，删去以它为根的子树，并释放相应的空间。

树的结构以广义表的形式给出。如A(B,)表示一颗有2个节点的树。其中根的data值为'A'，其左孩子为叶子节点，data值为'B'，右孩子为空。

建议使用如下数据结构

    typedef char TElemType; 

    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild, *rchild;
    //lchild,rchild分别为节点的左孩子，右孩子指针
    }BiTNode, *BiTree, *BiTLink;

输入格式共两行，第一行为以广义表的形式给出的树形结构。第二行为待删除子树根结点的元素值x。

输出格式共一行，为原树删除子树后的广义表表达。

输入格式

    A(B,C)
    B

输出格式

    A(,C)
    
注意事项:

若找不到该元素，则不做任何操作。


# 习题6.47
时间限制:1s

内存限制:128M

编写一个按层次便利二叉树的算法。

树的结构以广义表的形式给出。如A(B,)表示一颗有2个节点的树。其中根的data值为'A'，其左孩子为叶子节点，data值为'B'，右孩子为空。

建议使用如下数据结构

    typedef char TElemType; 

    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild, *rchild;
    //lchild,rchild分别为节点的左孩子，右孩子指针
    }BiTNode, *BiTree, *BiTLink;

输入格式共一行，为以广义表的形式给出的树形结构。

输出格式共一行，该二叉树按层次遍历的结果序列。以空格隔开。

输入格式

    A(B(D),C)

输出格式

    A B C D

注意事项:

若二叉树为空，输出空。
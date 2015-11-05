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


# 习题6.51
时间限制:1s

内存限制:128M

编写一个算法，输出以二叉树表示的算术表达式，若该表达式中需要含有括号，则在输出时应添上表示。

建议使用如下数据结构

    typedef char TElemType; 

    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild, *rchild;
    //lchild,rchild分别为节点的左孩子，右孩子指针
    }BiTNode, *BiTree, *BiTLink;
    
输入格式共一行，为该二叉树的广义表形式。

输出格式共一行，为所求算术表达式。

输入格式

    +(B,C)
    
输出格式

    B+C
    
注意事项:

若树为空，则输入第一行为结束标识，输出应为空。

# 习题6.50
时间限制:1s

内存限制:128M

假设以三元组(F,C,L/R)的形式输入一棵二叉树的诸边（其中F表示双亲结点的标识，C标识孩子结点的标识，L/R标识C为F的左孩子或右孩子），且在输入的三元组序列中，C是按层次顺序出现的。设结点的标识是字符类型。F='^'时C为根节点标识，若C也为'^'，则标识输入结束。试编写算法，由输入的三元组序列建立二叉树的二叉链表。

建议使用如下数据结构

    typedef char TElemType; 

    typedef struct BiTNode{
        TElemType data;
        struct BiTNode *lchild, *rchild;
    //lchild,rchild分别为节点的左孩子，右孩子指针
    }BiTNode, *BiTree, *BiTLink;

输入格式为若干行，每行分别为三个字符，描述如题。

输出格式共一行，为该二叉树的广义表形式。

输入格式

    ^AL
    ABL
    ACR
    ^^L

输出格式

    A(B,C)
    
注意事项:

若树为空，则输入第一行为结束标识，输出应为空。

# 习题6.54
时间限制:1s

内存限制:128M

假设以顺序表sa表示一棵完全二叉树。从根到叶结点按层次从1开始编号，同一层次从左到右编号，数据存储在对应的数组元素中。试编写算法由此顺序存储结构建立该二叉树的二叉链表。

建议使用如下数据结构

    typedef int TElemType;

    typedef struct{
    　　int size;
    　　TElemType elem[MAX_TREE_SIZE + 1];　　// elem[0]不用
    }SqBiTree;

    typedef struct BiTNode{
    　　TElemType data;
    　　struct BiTNode *lchild, *rchild;
    }BiTNode, *BiTree, *BiTLink;

输入格式共一行，顺序列出从根节点开始的各个节点元素，空格隔开，以'$'结束。

输出格式共一行，为二叉树结构的广义表达。

输入格式

    A B C D 
    
输出格式
    
    A(B(D),C)
    
注意事项:

若树为空，则输入第一行为结束标识，输出应为空。
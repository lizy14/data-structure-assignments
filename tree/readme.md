# 习题6.59
时间限制:1s

内存限制:128M

编写算法完成下列操作：无重复地输出以孩子兄弟链表存储的树T中所有的边

建议使用如下数据结构

typedef char ElemType;

typedef struct CSNode {
ElemType data;
struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
输入格式共n+1行，第一行只有一个数字n,表示共有n个节点。

接下来n行每行共两个数字，分别表示第n个节点的第一个孩子编号与下一个兄弟编号。节点编号从1开始，若无孩子或下一个兄弟，则编号为0。

输出格式共n-1行，每行描述一条边，边的输出顺序请按照从根节点开始，按层次从第一个孩子依次顺序输出。

输入格式

    3
    2 0
    0 3
    0 0
    
输出格式

    1 2
    1 3
    
注意事项:

若树为空，则输入第一行为0，输出应为空。

# 习题6.60
时间限制:1s

内存限制:128M

】编写算法完成下列操作：统计孩子-兄弟链表存储的树T中叶子的个数。

建议使用如下数据结构

typedef char ElemType;

typedef struct CSNode {
ElemType data;
struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
输入格式共n+1行，第一行只有一个数字n,表示共有n个节点。

接下来n行每行共两个数字，分别表示第n个节点的第一个孩子编号与下一个兄弟编号。节点编号从1开始，若无孩子或下一个兄弟，则编号为0。

输出格式共1行，输出该树中叶子的个数。

输入格式

    3
    2 0
    0 3
    0 0

输出格式

    2

注意事项:

若树为空，则输入第一行为0，输出应为0。

# 习题6.66
时间限制:1s

内存限制:128M

编写算法完成下列操作：将一个使用双亲表示的树转化为使用孩子兄弟链表表示的算法

建议使用如下数据结构

typedef char ElemType;

typedef struct CSNode {
ElemType data;
struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;
输入格式共n+1行，第一行只有一个数字n,表示共有n个节点，编号为1，2，3..n。

接下来n行每行1个数字，表示该节点的双亲。若无双亲则数字为0.

输出格式共n行，每行两个数字，分别输出该编号节点的第一个孩子节点编号与下一个兄弟编号，若无则输出0。

输入格式

    3
    0
    1
    1
    
输出格式

    2 0
    0 3
    0 0
    
注意事项:

若树为空，则输入第一行为0，输出应为空。

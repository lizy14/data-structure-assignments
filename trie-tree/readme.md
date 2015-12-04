# 习题9.42

时间限制:1s

内存限制:128M

试写在Trie树中插入一个关键字的算法。

建议使用如下数据结构

    typedef enum { Leaf, Branch } NodeKind;
    typedef char KeyType[h];

    typedef struct TrieNode{
    　　NodeKind kind;
    　　union{
    　　　　struct { KeyType key; /* Record *infoptr; */  } lf;
    　　　　struct { TrieNode *ptr[MAX_KEY]; int num; } bh;
    　　};
    }TrieNode, *TrieTree, *TrieLink;

其中infoptr在本题中不使用，h和MAX_KEY为预定义的常数。num可自行定义。
输入格式共四行,第一行为待操作trie树的单词表，使用逗号隔开。元素为单词。

第二至四行为三个待插入单词a, b, c。

输出格式共一行，为插入节点后的trie树广义表示。

输入格式

    DATA,STRUCTURE
    KALEIDIA
    STUDENT
    TSINGHUA

输出格式

    (DATA,KALEIDIA,((STRUCTURE,STUDENT)),TSINGHUA)

样例输入输出说明:

此处用广义表表示Trie树，仅需输出非空节点，使用括号表示指针指向子节点，输出单词的叶子节点位置，如对于a,aa,aaaa,aab的trie树广义表为((a,(aa,aaaa,aab)))。若输出树为空，则输出应也为空。输出顺序请按照字母表顺序输出。
# 习题2
时间限制:1s

内存限制:128M

给定一个非负权重的有向图，实现 Dijkstra 算法，计算出某点到其他点之间的最短路径和长度。

给定的图是有向图（不含有重边或自环，但可能有环路），边的权重均为正整数，任意两点之间的最短路径仅有一条，并且长度不会超过int表示范围。

测试时使用数字作为元素，第一行是图中节点数量n和边数量m。第2到m+1行是m条有向边，每条边由起点start，终点end，权重weight组成，其中节点从0开始编号。 接下来一行是查询数量q，和查询的起点start，后续共有q行表示查询终点end。

输出内容应该包括q行查询结果，如果存在从起点到终点的路径，则输出最短路径（节点的序列）和对应的长度（如果起点和终点相同，则长度为0），形式如“1-3-6 4”,"3-3 0"；若无路径，则输出“NO PATH”。

输入格式

    9 13
    0 1 2
    0 3 3
    0 5 2
    1 4 4
    2 4 5
    3 6 3
    4 8 1
    5 6 2
    5 4 2
    6 7 3
    7 5 5
    8 5 2
    8 7 1
    5 0
    2
    3
    4
    6
    7
    
输出格式

    NO PATH
    0-3 3
    0-5-4 4
    0-5-6 4
    0-5-4-8-7 6
    
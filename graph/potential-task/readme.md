# 习题3
时间限制:1s

内存限制:128M

给定各工序的时间和先序工序，求关键路径及各个工序允许延误的时间（PT图）。

给定工序编号，工序所需时间以及对应的先序工序，其中工序所需时间均为正整数，并且关键路径的总时间不会超过int表示范围。

测试时使用数字作为元素，第一行是工序的个数n，第2到n+1行是n个工序的说明，每个工序由工序号Index，工序时间Time，先序工序PreIndex组成，其中工序从0开始编号。 若无先序工序，则先序工序处为空；若有多个先序工序，则用逗号隔开，具体样式请参考样例。

输出内容应该包括关键路径的时间，关键路径（工序组成的路径，形式如“0-1-3-6-end”，end是虚拟结束节点，如果有多条关键路径，则按照字典顺序从小到大输出，每行输出一条），各工序允许延误时间（共 n 行），具体样式请参考样例。

输入格式

    13
    0 2
    1 6 0
    2 3 0
    3 2 1
    4 4 2,3
    5 3 3
    6 8 3
    7 4 3
    8 2 6,7
    9 3 6
    10 8 7,4
    11 5 9
    12 6 10

输出格式

    28
    0-1-3-4-10-12-end
    0-1-3-7-10-12-end
    0
    0
    5
    0
    0
    15
    2
    0
    8
    2
    0
    2
    0

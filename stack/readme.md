# 习题3.17
时间限制:1s

内存限制:128M

试写一个算法，识别依次读入的一个以@为结束符的字符序列是否为形如'序列1&序列2'模式的字符序列。其中序列1和序列2都不含字符&且序列2是序列1的逆序列。

输入格式共一行，为待识别字符序列

输出格式仅一行，若是该中序列，则输出'true'。否则输出'false'

输入格式

    a+b&b+a@
    
输出格式

    true
    

# 习题3.19
时间限制:1s

内存限制:128M

假设一个算术表达式中可以包含三种括号：圆括号'('和')'、方括号'['和']'、和花括号'{'和'}'。且这三种括号可以按任意的次序嵌套使用。试利用栈操作编写判别给定表达式中所含括号是否正确配对出现的算法。

输入格式共一行，为待测试表达式

输出仅一行，仅需输出"true"或者"false"以表示括号匹配正确与否

输入格式

    ({ }5# {}[ab]   )({@[]}!)
    
输出格式

    true
    
注意事项:

输入串以顺序表方式给出，非括号字符可以直接忽略；规定，若输入串为空，则返回true



# 习题3.22
时间限制:1s

内存限制:128M

假设表达式由数字和双目四则运算符（'+', '-', '*', '/'）构成。试利用栈实现一个算法，将一个通常书写形式且书写正确的表达式转换为逆波兰式（后缀表达式），可参考习题3.21。同时将转换后的逆波兰式求值。最后仅需输出求值结果。

输入格式共一行，为待求值表达式

输出仅一行，为表达式结果

输入格式

    1+2+3+4+5
    
输出格式

    15
    
注意事项:

表达式仅占一行，以回车结束，并保证表达式计算的合理性，不需判断除零等情况。表达式的计算应遵循同级运算从左往右，先乘除后加减的原则。
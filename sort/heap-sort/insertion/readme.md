# ϰ��10.34

ʱ������:1s

�ڴ�����:128M

��д������ʱ��ʵ�ֲ��������ݷ�����������p��Ԫ�صĶѣ��ܹ���O(log n)�㷨���Ӷ���ӵ�p+1��Ԫ�ء�

    #define MAXSIZE 200 //��󳤶�

    typedef int KeyType;
    typedef int InfoType;

    typedef struct {
        KeyType key;
        InfoType otherinfo;
    }RcdType;

    typedef struct {
        RcdType r[MAXSIZE + 1]; //r[0]���û��������ڱ���Ԫ
        int length;
    }SqList;
    
�����ʽ��һ��Ϊһ�������������ܸ���n���ڶ��й������n�����֡�������ΪҪ���ӵ�����k��

�����һ�У���������Ľ����

�����ʽ

    2
    69 50
    38

�����ʽ

    38 50 69

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int sushu(int x);

int main()
{
    int result;
    for (int i=1;i<=100;i++)
    {
        result = sushu(i);
        if(result == 1) {printf("%d\n",i);}  //����������ֵΪ1ʱ����ӡ��Ӧ��i��ֵ
    }
    return 0;
}
int sushu(int x) //����һ�����������������ʱ������ֵΪ1�ĺ���
{
    if(x==1){return 0;}
    int num = (int)sqrt(x);
    for (int k=2;k<=num;k++)
    {
        if(x%k==0){return 0;}
    }
    return 1;
}

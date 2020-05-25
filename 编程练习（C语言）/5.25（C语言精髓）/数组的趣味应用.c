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
        if(result == 1) {printf("%d\n",i);}  //当函数返回值为1时，打印对应的i的值
    }
    return 0;
}
int sushu(int x) //构造一个当输入的数是素数时，返回值为1的函数
{
    if(x==1){return 0;}
    int num = (int)sqrt(x);
    for (int k=2;k<=num;k++)
    {
        if(x%k==0){return 0;}
    }
    return 1;
}

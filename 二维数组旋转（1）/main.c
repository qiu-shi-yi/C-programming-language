#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[10][10] = {{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20},{21,22,23,24,25,26,27,28,29,30},{31,32,33,34,35,36,37,38,39,40},
                        {41,42,43,44,45,46,47,48,49,50},{51,52,53,54,55,56,57,58,59,60},{61,62,63,64,65,66,67,68,69,70},{71,72,73,74,75,76,77,78,79,80},
                        {81,82,83,84,85,86,87,88,89,90},{91,92,93,94,95,96,97,98,99,100}};
    int a,b,c;
    int i,j,m,n;
    int u;
    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("%4d",num[i][j]);
        }
        printf("\n");
    }
    printf("请输入横坐标：");
    scanf("%d",&a);
    printf("请输入纵坐标：");
    scanf("%d",&b);
    printf("请输入旋转度：");
    scanf("%d",&c);
    /*根据a，b确定要旋转的框*/
    if (a>=b)
    {
        if(a>5&&b>5){u=10-a+1;}
        else u=b;
    }
    else
    {
        if(a>5&&b>5){u=10-b+1;}
        else u=a;
    }
    /*从原数组中取出位置要改变的所有数字*/
    int num_home[50]={0};
    int number = 0;
    for (int right_1=u-1;right_1<=9-u;right_1++)
    {
        num_home[number] = num[u-1][right_1];
        number++;
    }
    for (int down_1=u-1;down_1<=9-u;down_1++)
    {
        num_home[number] = num[down_1][10-u];
        number++;
    }
    for (int left_1=10-u;left_1>u-1;left_1--)
    {
        num_home[number] = num[10-u][left_1];
        number++;
    }
    for (int up_1=10-u;up_1>u-1;up_1--)
    {
        num_home[number] = num[up_1][u-1];
        number++;
    }

    /*根据旋转度排序成新的数组*/
    int c_num;
    c_num = 4*(11-2*u);
    //printf("c的值是：%d\n",c_num);
    int new_nums[c_num];
    if(c>0)
    {
        for (int h=0;h<c_num;h++)
        {
            if(h<c){ new_nums[h] = num_home[c_num-c+h];}
            else new_nums[h] = num_home[h-c];
        }
    }
    else
    {
        for (int h=0;h<c_num;h++)
        {
            if(h<c_num+c){new_nums[h] = num_home[h-c];}
            else new_nums[h] = num_home[h-c_num-c];
        }
    }
   /*将排序后的新数组重新填入*/
    int g=0;
    for (int right_2=u-1;right_2<=9-u;right_2++)
    {
        num[u-1][right_2] = new_nums[g];
        g++;
    }
    for (int down_2=u-1;down_2<=9-u;down_2++)
    {
        num[down_2][10-u] = new_nums[g];
        g++;
    }
    for (int left_2=10-u;left_2>u-1;left_2--)
    {
        num[10-u][left_2] = new_nums[g];
        g++;
    }
    for (int up_2=10-u;up_2>u-1;up_2--)
    {
        num[up_2][u-1] = new_nums[g];
        g++;
    }
    for (m=0;m<10;m++)
    {
        for (n=0;n<10;n++)
        {
            printf("%4d",num[m][n]);
        }
        printf("\n");
    }
    return 0;
}

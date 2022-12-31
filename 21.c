//输出杨辉三角
#include<stdio.h>
long A(int a,int b);
int main()
{
    int m,n;
    scanf("%d",&m);//数据组数
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&n);
        for (int j = 0; j < n; j++)
        {
            for(int k = 0;k <= j;k++)
            {
                printf("%ld ",A(j,k)/A(k,k));
            }
            printf("\n");
        }
        
    }
    system("pause");
    return 0;
}
//排列公式
long A(int a,int b)
{
    long p = 1;
    for(int i = 0;i<b;i++)
    {
        p = p * a;
        a--;
    }
    return p;
}
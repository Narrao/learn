// 指定范围内的素数求和
#include <stdio.h>
int isp(int a,int count,int p[]);
int main()
{
    int n = 5000,count = 1,m,k,sum=2;
    int p[n];// 存储已找到的素数
    scanf("%d",&m);
    p[0] = 2;
    k=3;
    while(p[count - 1] < m && k < m)
    {
        if(isp(k,count,p))
        {
            p[count] = k;
            sum += p[count];
            count++;
        }
        k++;

    }
    printf("%d",sum);
    system("pause");
    return 0;
}
// 判断是否为素数，用之前的素数除
int isp(int a,int count,int p[])
{
    int flag = 1;
    for(int i = 0;i < count;i++)
    {

        if(a % p[i] == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

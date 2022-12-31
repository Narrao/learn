#include<stdio.h>
long long f(int a);
int main()
{
    int k;
    scanf("%d",&k);
    for(int i = 0;i < k;i++)
    {
        int n;
        scanf("%d",&n);
        long long sum =0;
        for(int j =1;j <= n;j++)
        {
            sum = (sum+f(j))%1000000;
        }
        if(n==0)sum=1;
        printf("%ld\n",sum%1000000);
    }
    system("pause");
    return 0;
}
long long f(int a)
{
    long long pow=1;
    if(a<30)
    {
        for (int i = 1; i <= a; i++)
        {
            pow=(pow*i)%1000000;
        }
    }else pow=0;
    return pow%1000000;
}
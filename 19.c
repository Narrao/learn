#include<stdio.h>
long x(long a,long n);
int main()
{
    long a,n,sum=0;
    scanf("%d%d",&a,&n);
    for(int i=1;i<=n;i++)
    {
        sum = sum + x(a,i);
    }
    printf("%ld",sum);
    system("pause");
    return 0;
}
long x(long a,long n)
{
    long sum=0;
    for(int i=1;i<=n;i++)
    {
        sum=sum*10+a;
    }
    return sum;
}
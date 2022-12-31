#include<stdio.h>
void sort(long long x,long long *y );
int main()
{
    long long a=0,b=0;
    scanf("%ld",&a);
    sort(a,&b);
    while(a!=b&&a < 2147483648ll)
    {
        a=a+b;
        sort(a,&b);
    }
    if(a>2147483648ll)printf("No");
    else printf("%ld",a);
    system("pause");
    return 0;
}
void sort(long long x,long long *y )
{
    int t;
    *y = 0;
    while(x!=0)
    {
        t = x % 10;
        *y = *y * 10 + t;
        x = x / 10;
    }
}
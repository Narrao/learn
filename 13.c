#include <stdio.h>
int main()
{
    long n, a, b, c;
    scanf("%d",&n);
    for(long i = 0;i < n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if((a*a==b*b+c*c||
        b*b==a*a+c*c||
        c*c==a*a+b*b)){
            printf("Yes\n");
        }else printf("No\n");
    }
    system("pause");
    return 0;
}
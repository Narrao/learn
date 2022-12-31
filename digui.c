#include <stdio.h>

int sum( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf ("%d\n", sum(n));

    return 0;
}

/* 你的代码将被嵌在这里 */
int sum( int n )
{
    int s=0;
    if(n>0)s=s+sum(n-1);
    return s;
}
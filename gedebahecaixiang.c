#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );
    
int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }
    system("pause");
    return 0;
}

/* 你的代码将被嵌在这里 */

int prime( int p )
{
    for (int i = 2; i < p; i++)
    {
        if (p % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
void Goldbach( int n )
{
    for (int i = 2; i < n; i++)
    {
        if (prime(i) == 1)
        {
            int a = i;
            int b = n - a;
            if (prime(b)==1)
            {
                printf("%d=%d+%d",n,a,b);
                break;
            }
        }
    }
}

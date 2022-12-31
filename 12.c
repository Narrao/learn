#include <stdio.h>
#include <math.h>
int narcissistic( int number );
void PrintN( int m, int n );
    
int main()
{
    int m, n, t;
    scanf("%d",&t);
    for (int i = 0;i < t;i++)
    {
        scanf("%d%d",&m,&n);
        PrintN(m,n);
    }
    
    return 0;
}

/* 你的代码将被嵌在这里 */

int narcissistic( int number )
{
    int sum=0,temp = number,len = 0;
    while(temp>0)
    {
        len++;
        temp = temp / 10;
    }
    temp = number;
    while(temp > 0)
    {   
        sum = sum + pow(temp % 10,len);
        temp = temp / 10;
    }
    return sum == number?1:0;
}
void PrintN( int m, int n )
{
    int count = 0;
    for(int i = m;i <= n;i++)
    {
        if ( narcissistic(i) ) {printf("%d ", i);count++;}
    }
    if(count == 0){printf("-1");}
    printf("\n");
}
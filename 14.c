#include <stdio.h>
int main()
{
    int m,max = -1,a,maxa;
    scanf("%d",&m);
    for(int i = 0;i < m;i++)
    {
        scanf("%d",&a);
        if(a<0&&-a > max)
        {
            max = -a;
            maxa = a;
        }else if(a>max)
        {
            max = a;
            maxa = a;
        }

    }
    printf("%d",maxa);
    return 0;
}
#include <stdio.h>
int main(void)
{
    int i,n,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i<=n/2+1)
        {
            printf("%*s",n-2*i+1,"");
            for(x=1;x<=2*i-1;x++)
            {
                if(x==2*i-1)
                {
                    printf("* \n");
                }
                else
                {
                    printf("* ");
                }
            }
        }
        else
        {
            printf("%*s",(i-4)*2," "); 
            for(x=1;x<=n+8-2*i;x++)
            {
                if(x==n+8-2*i)
                {
                    printf("* \n");
                }
                else
                {
                    printf("* ");
                }
            }  
        }
    }
    system("pause");
 return 0;
}
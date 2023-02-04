#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    int s[1000];
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        if(n%2==0)
        {
            printf("YES\n");
            for(int j=0;j<n/2-1;j++)
            {
                printf("1 -1 ");
            }
            printf("1 -1\n");
        }
        else if(n==3) printf("NO\n");
        else 
        {
            printf("YES\n");
            for(int j=0;j<(n-1/2);j++)
            {
                printf("%d ",3-n);
                printf("%d ",n-1);
            }
            printf("%d\n",3-n);
        }
    }
    system("pause");
    return 0;
}
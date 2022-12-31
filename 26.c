#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&m);
        while(m%2==0)m=m/2;
        while(m%3==0)m=m/3;
        while(m%5==0)m=m/5;
        if(m==1)printf("true\n");
        else printf("false\n");
    }
    system("pause");
    return 0;
}
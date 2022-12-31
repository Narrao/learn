#include<stdio.h>
int main()
{
    int n,count=0,j;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        for(j = 0;j <i;j++)
        {
            if(a[j]==a[i])break;
        }
        if(j==i)count++;
    }
    printf("%d",count);
    system("pause");
    return 0;
}
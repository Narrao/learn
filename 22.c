#include<stdio.h>
int main()
{
    int m,n,t;
    int a[1000];
    scanf("%d%d",&m,&n);
    for(int i = 0;i < m+n;i++)scanf("%d",&a[i]);
    for(int i = 0;i < n+m-1;i++)
    {
        for(int j = 0;j < n+m-i-1;j++)
        {
            if(a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }

    }
    for(int i = 0;i < m+n;i++)printf("%d ",a[i]);
    system("pause");
    return 0;
}
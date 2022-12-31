#include<stdio.h>
void print(int n);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int a;
        scanf("%d",&a);
        print(a);
    }
    system("pause");
    return 0;
}
void print(int n)
{
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            printf("%d*%d=%d ",i,j,i*j);
        }
        printf("\n");
    }
}
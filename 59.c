#include<stdio.h>
int main()
{
    int a[1005]={1},b[1005]={1},n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<100;j++)
        {
            b[j]=b[j]*i;
        }
        for(int j=0;j<100;j++)
        {
            if(b[j]>9)
            {
                b[j+1]=b[j+1]+b[j]/10;
                b[j]=b[j]%10;
            }
        }
        for(int j=0;j<100;j++)
        {
            a[j]=a[j]+b[j];
        }
        for(int j=0;j<100;j++)
        {
            if(a[j]>9)
            {
                a[j+1]=a[j+1]+a[j]/10;
                a[j]=a[j]%10;
            }
        }
    }
    int i;
    for(i=1000;a[i]!=0;i--);
    for (int  j = i; j >=i; j--)
    {
        printf("%d",a[j]);
    }
    
    system("pause");
    return 0;
}
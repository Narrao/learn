#include<stdio.h>
int main()
{   
    int a[3],b[5],n;
    scanf("%d",&n);
    for(int j = 0;j < n; j++)
    {
        for(int i=0;i<3;i++)a[i]=0;
        for(int i=0;i<5;i++)
        {
            scanf("%d",&b[i]);
            if(b[i]>0)a[0]++;
            else if(b[i]<0)a[1]++;
            else a[2]++;
        }
        printf("%d %d %d\n",a[0],a[1],a[2]);

    }
    system("pause");
    return 0;
}
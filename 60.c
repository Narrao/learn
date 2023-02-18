#include<stdio.h>
int main()
{
    int n,w,a[300000];
    int min=-1,count;
    scanf("%d%d",&n,&w);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=w/10;i++)
    {
        count=0;
        for(int j=1;j<n;j++)
        {
            if(a[j]!=(a[0]+j*i))count++;
            if(a[j]>w)count=n;
        }
        if(count<min||min==-1)min=count;
    }
    printf("%d",min);
    system("pause");
    return 0;
}
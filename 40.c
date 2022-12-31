#include<stdio.h>
int sort(int a[],int begin,int w);
int main()
{
    int a[100],ans[100];
    int w,n;
    while(scanf("%d %d",&w,&n)==2)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        if(w%2==0)printf("ERROR");
        else
        {
            for(int i=0;i<=w/2;i++)ans[i]=a[i];
            for(int i=0;i<=n-w;i++)
            {
                ans[i+w/2]=sort(a,i,w);
            }
            for(int i=n-1;i>=n-w/2;i--)ans[i]=a[i];
            for(int i=0;i<n;i++)printf("%d ",ans[i]);
            printf("\n");
        }
    }
    system("pause");
    return 0;
}
int sort(int a[],int begin,int w)
{
    int middle=0;
    int b[w];
    for(int i=begin,j=0;j<w;i++,j++)b[j]=a[i];
    for(int i=0;i<w;i++)
    {
        for(int j=0;j<w-i-1;j++)
        {
            int t;
            if(b[j]>b[j+1]){
                t=b[j];b[j]=b[j+1];b[j+1]=t;
            }
        }
    }
    return b[w/2];
}
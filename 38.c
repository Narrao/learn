#include<stdio.h>
void copy(unsigned long long *p1,unsigned long long *p2,int n);
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    unsigned long long a[n][n],b[n][n],c[n][n];
    unsigned long long *p2 = &b[0][0],*p1 =&c[0][0];
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            scanf("%d",&a[i][j]);
            c[i][j]=a[i][j];
        }
    }
    for(int i = 0;i < k-1;i++)
    {
        copy(p1,p2,n);
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                c[x][y]=0;
                for(int m =0;m<n;m++)c[x][y]=c[x][y]+a[x][m]*b[m][y];
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
void copy(unsigned long long *p1,unsigned long long *p2,int n)
{
    for(int i=0;i<n*n;i++)
    {
        *(p2+i)=*(p1+i);
    }
}
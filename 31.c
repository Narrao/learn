#include<stdio.h>
int main()
{
    int n=0,m;
    int a[100][100];
    scanf("%d",&m);
    do
    {
        scanf("%s",a[n]);
        n++;
    }while(getchar()!='\n');
    if(n<m)printf("error");
    else {
        int j=n-m,count=n;
        while (count>0)
        {
            printf("%s ",a[j]);
            j++;
            if(j==n)j=0;
            count--;
        }
        
    }
    system("pause");
    return 0;
}
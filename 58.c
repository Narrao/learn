#include<stdio.h>
#include<string.h>
int main()
{
    char x[101];
    int max=-1,a[26]={0};
    for(int i=0;i<4;i++)
    {
        fgets(x,101,stdin);
        int j=0;
        while(x[j]!=0)
        { 
            if(x[j]<='Z'&&x[j]>='A')
            {
                a[x[j]-65]++;
                if(max<a[x[j]-65])max=a[x[j]-65];
            }
            j++;
        }
    }
    int count=max;
    for(int i=max;i>=1;i--)
    {
        if(a[0]>=i)printf("*");
        else printf(" ");
        for(int j=1;j<26;j++)
        {
            if(a[j]>=i)printf(" *");
            else printf("  ");
        }
        printf("\n");
    }
    printf("A");
    for(int i=1;i<=25;i++)printf(" %c",i+65);
    system("pause");
    return 0;
}
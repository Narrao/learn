#include<stdio.h>
#include<string.h>
void exist(const char in[][101],int *p,const char cin[],const int n);
void cout(const int flag[]);
int main()
{
    int n;
    char in[50][101]={""};
    int flag[26]={0};
    char cin[101];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",in[i]);
    }
    scanf("%s",cin);
    exist(in,flag,cin,n);
    cout(flag);
    system("pause");
    return 0;
}

void exist(const char in[][101],int *p,const char cin[],const int n)
{
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<strlen(cin);j++)
        {
            if(in[i][j]!=cin[j])break;
        }
        if(j==strlen(cin))
        {
            *(p+in[i][strlen(cin)]-65)=1;
        }
    }
}

void cout(const int flag[])
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(i==1&&j<=3)printf("*");
            else if(((i==1&&j>3)||(i>=2&&i<=3)||(i==4&&j<=5))&&flag[(i-1)*8+j-4]==1)printf("%c",(i-1)*8+j-4+65);
            else printf("*");
        }
        printf("\n");
    }
}
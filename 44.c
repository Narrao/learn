#include<stdio.h>
#include<string.h>
int equal(const char a,const char b);
int main()
{
    char a[1000],b[1000];
    fgets(a,999,stdin);
    scanf("%s",b);
    int lena=strlen(a),lenb=strlen(b);
    int begin[lena],end[lena],k=0;
    for(int i=0;i<lena;i++)
    {
        if(equal(a[i],b[0]))
        {
            int j=0;
            for(;j<lenb;j++)
            {
                if(!equal(a[i+j],b[j]))break;
            }
            if(j==lenb)
            {
                begin[k]=i;
                end[k]=i+lenb;
                k++;
            }
        }
    }
    k=0;
    for(int i=0;i<lena;i++)
    {
        if(i==begin[k])printf("/*");
        if(i==end[k])
        {
            printf("*/");
            k++;
        }
        putchar(a[i]);
    }
    system("pause");
    return 0;
}
int equal(const char a,const char b)
{
    int flag=0;
    if(a+32==b||a==b||a-32==b)flag=1;
    return flag;
}
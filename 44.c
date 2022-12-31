#include<stdio.h>
#include<string.h>
int equal(const char a,const char b);  //忽略大小写判断字母是否相等
int main()
{
    char a[1000],b[1000];
    fgets(a,999,stdin);   //输入句子
    scanf("%s",b);        //输入要替换的子串
    int lena=strlen(a),lenb=strlen(b);  //两个字符串的长度
    int begin[lena],end[lena],k=0;   //分别标记第k个子串在句子中的开始和结束位置

    //标记第k个子串在句子中的开始和结束位置
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

    //输出，当遇到标记的地方就先输出‘/*’或‘*/’
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
#include<stdio.h>
#include<string.h>
void get(char *p);
int in(char *p,char *p2);
void getnum(char *p,int *p1,int *p2);
void remove_blank(char *p1,const char *p);
int main()
{
    int n;
    scanf("%d",&n);getchar();
    char name[n][52];
    int score[n],jscore[n];

    //获取队名初始化分数
    for(int i=0;i<n;i++)
    {
        char *p=name[i];
        get(p);
        score[i]=0;
        jscore[i]=0;
    }

    //记录分数
    char a[100];
    for(int i=0;i<n*(n-1)/2;i++)
    {
        int x=-1,y=-1;
        get(a);
        for(int j=0;j<n;j++)
        {
            if(in(name[j],a))
            {
                if(x==-1)x=j;
                else y=j;
            }
        }
        //printf("%d %d\n",x,y);
        int s1,s2;
        getnum(a,&s1,&s2);
        if(s1>s2)
        {
            score[x]+=3;
        }
        else if(s1<s2)
        {
            score[y]+=3;
        }else{
            score[x]++;
            score[y]++;
        }
        jscore[x]=jscore[x]+s1-s2;
        jscore[y]=jscore[y]+s2-s1;
    }

    //冒泡加索引排序
    int index[n];
    for(int i=0;i<n;i++)index[i]=i;
    for(int i=0;i<n-1;i++)
    {
        int k=i;
        for(int j=i+1;j<n;j++)
        {
            if((score[index[j]]>score[index[k]])||
            (score[index[j]]==score[index[k]]&&jscore[index[j]]>jscore[index[k]])||
            (score[index[j]]==score[index[k]]&&jscore[index[j]]==jscore[index[k]]&&strcmp(name[index[j]],name[index[k]])<0))
            k=j;
        }
        if(k!=i)
        {
            int t=index[k];
            index[k]=index[i];
            index[i]=t;
        }
    }

    //输出前一半
    for(int i=0;i<n/2;i++)
    {
        printf("%s\n",name[index[i]]);
    }

    //检查后一半是否有和最后一个相等的也输出
    for(int i=n/2;i<n;i++)
    {
        if(score[index[n/2-1]]==score[index[i]]&&jscore[index[n/2-1]]==jscore[index[i]])printf("%s\n",name[index[i]]);
    }
    
    system("pause");
    return 0;
}

//获取字符串
void get(char *p)
{
    char a;
    int i=0;
    while((a=getchar())!='\n')*(p+i++)=a;
    *(p+i)=0;
}

//判断是否为字符串的子串
int in(char *p,char *p2)
{
    int flag = 0;
    char c1[100],c2[100];
    remove_blank(c1,p);
    remove_blank(c2,p2);
    for(int i=0;i<strlen(c2);i++)
    {
        if(c1[0]==c2[i])
        {
            int j=0;
            for(;j<strlen(c1);j++)
            {
                flag=1;
                break;
            }
        }
        if(flag)break;
    }
    return flag;
}

//获取分数
void getnum(char *p,int *p1,int *p2)
{
    *p1=-1;
    *p2=-1;
    for(int i=strlen(p);i>=0;i--)
    {
        if(*(p+i)>='0'&&*(p+i)<='9')
        {
            if(*p2==-1)
            {
                int t=1;
                *p2=0;
                while (*(p+i)>='0'&&*(p+i)<='9')
                {
                    *p2=*p2+t * (*(p+i)-48);
					i--;
                    t=t*10;
                }
            }
            else if(*p1==-1)
            {
                int j=0,t=1;
                *p1=0;
                while (*(p+i)>='0'&&*(p+i)<='9')
                {
                    *p1=*p1+t * (*(p+i)-48);
                    i--;
                    t=t*10;
                }
            }
        }
        if(*p1!=-1&&*p2!=-1)break;
    }
}

//删除空格
void remove_blank(char *p1,const char *p)
{
    int t=0;
    for(int i=0;i<strlen(p);i++)
    {
        if(*(p+i)!=' ')*(p1+t++)=*(p+i);
    }
    *(p1+t)=0;
}
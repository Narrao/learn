#include<stdio.h>
#include<string.h>
char *mid(char *str,int start,int length);
int main()
{
    struct team
    {
        char name[51];
        int score;
        int jscore;
    };
    
    int n;
    scanf("%d",&n);getchar();
    struct team team[1000];

    //初始化分数,获取队伍名称
    for(int i=0;i<n;i++)
    {
        int j=0;char a;
        while((a=getchar())!='\n')team[i].name[j++]=a;
        team[i].name[j]=0;
        team[i].score=0;
        team[i].jscore=0;
    }

    //获取每组分数和净分数
    {
        char a[1000];
        int x,y,p,q;
        for(int i=0;i<n*(n-1)/2;i++)
        {
            x=-1;y=-1,p=0,q=0;
            fgets(a,999,stdin);
            //找第一组下标
            for(int j=0;j<n;j++)
            {
                if(strcmp(team[j].name,mid(a,0,strlen(team[j].name)))==0)x=j;
            }
            
            //找第二组下标
            int k = strlen(team[x].name)+1;
            for(int i = k;i < strlen(a)-k;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(strcmp(team[j].name,mid(a,i,strlen(team[j].name)))==0)
                    {
                        y=j;
                    }
                }
            }

            //找分数
            int count = 0;//记录遇到‘-’的个数，从的二个-开始算后面的比分
            for(int j=0;j<strlen(a);j++)
            {
                if(a[j]=='-')count++;
                if(a[j]==':')
                {
                    int m=0;
                    while(!(a[j+m]>='0'&&a[j+m]<='9'))m++;
                    while ((a[j+m]>='0'&&a[j+m]<='9'))
                    {
                        q=q*10+a[j+m]-48;
                        m++;
                    }
                }
                if(a[j]=='-'&&count==2)
                {
                    int m=0;
                    while(!(a[j+m]>='0'&&a[j+m]<='9'))m++;
                    while ((a[j+m]>='0'&&a[j+m]<='9'))
                    {
                        p=p*10+a[j+m]-48;
                        m++;
                    }
                }
            }
            // printf("%s-%s:%d-%d\n",team[x],team[y],q,p);
            if(q>p)
            {
                team[x].score=team[x].score+3;
                team[x].jscore=team[x].jscore+q-p;
                team[y].jscore=team[y].jscore+p-q;
            }else if(q<p)
            {
                team[y].score=team[y].score+3;
                team[x].jscore=team[x].jscore+q-p;
                team[y].jscore=team[y].jscore+p-q;
            }else{
                team[x].score++;
                team[y].score++;
            }
        }
        
    }
    // for(int i=0;i<n;i++)
    // {
    //     printf("%s\t%d\t%d\n",team[i].name,team[i].score,team[i].jscore);
    // }

    int k;
    struct team *t;
    for(int i=0;i<n;i++)
    {
        k=i;
        for(int j=i+1;j<n;j++)
        {
            if(team[k].score<team[j].score||
            (team[k].score==team[j].score&&team[k].jscore<team[j].jscore)||
            (team[k].score==team[j].score&&team[k].jscore==team[j].jscore&&(strcmp(team[k].name,team[j].name)==1)))
            k=j;
        }
        if(k!=i)
        {
            *t=team[k];
            team[k]=team[i];
            team[i]=*t;
        }
    }

    //输出前一半
    for(int i=0;i<n/2;i++)
    {
        printf("%s\n",team[i].name);
    }

    //检查后一半是否有和最后一个相等的也输出
    for(int i=n/2;i<n;i++)
    {
        if(team[n/2-1].score==team[i].score&&team[n/2-1].jscore==team[i].jscore)printf("%s\n",team[i].name);
    }
    system("pause");
    return 0;
}
char *mid(char *str,int start,int length)
{
    static char result[256];
    strncpy(result,str+start,length);
    result[length]=0;
    return result;
}
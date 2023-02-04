#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);getchar();
    char team[n][51];
    int score[n],jscore[n];
    for(int i=0;i<n;i++)
    {
        score[i]=0;
        jscore[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        int j=0;char a;
        while((a=getchar())!='\n')team[i][j++]=a;
        team[i][j]=0;
    }
    {
        char a[1000];
        int x,y,p,q;
        for(int i=0;i<n*(n-1)/2;i++)
        {
            x=0;y=0,p=0,q=0;
            fgets(a,999,stdin);
            //找第一组下标
            for(int j=0;j<n;j++)
            {
                int k = 0;
                if(team[j][0]==a[k])
                {
                    int m=0;
                    for(;m<strlen(team[j]);m++)
                    {
                        if(team[j][m]!=a[k+m])break;
                    }
                    if(m==strlen(team[j]))
                    {
                        x=j;
                        break;
                    }
                }
            }
            //找第二组下标
            for(int j=0;j<n;j++)
            {
                int k = strlen(team[x])+1;
                if(team[j][0]==a[k])
                {
                    int m=0;
                    for(;m<strlen(team[j]);m++)
                    {
                        if(team[j][m]!=a[k+m])break;
                    }
                    if(m==strlen(team[j]))
                    {
                        y=j;
                        break;
                    }
                }
            }
            //找分数
            for(int j=strlen(team[x])+strlen(team[y]);j<strlen(a);j++)
            {
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
                if(a[j]=='-')
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
            if(q>p)
            {
                score[x]=score[x]+3;
                jscore[x]=jscore[x]+q;
                jscore[y]=jscore[y]-p;
            }else if(q<p)
            {
                score[y]=score[y]+3;
                jscore[x]=jscore[x]-q;
                jscore[y]=jscore[y]+p;
            }else{
                score[x]++;
                score[y]++;
                jscore[x]=jscore[x]+q;
                jscore[y]=jscore[y]+p;
            }
        }
        
    }
    int index[n];
    for(int i=0;i<n;i++)index[i]=i;
    int k,t;
    for(int i=0;i<n;i++)
    {
        k=i;
        for(int j=i+1;j<n;j++)
        {
            if(score[index[k]]<score[index[j]]||
            (score[index[k]]==score[index[j]]&&jscore[index[k]]<jscore[index[j]])||
            (score[index[k]]==score[index[j]]&&jscore[index[k]]==jscore[index[j]]&&(strcmp(team[index[k]],team[index[j]])==-1)))
            k=j;
        }
        if(k!=i)
        {
            t=index[k];
            index[k]=index[i];
            index[i]=t;
        }
    }
    for(int i=0;i<n/2;i++)
    {
        printf("%s\n",team[index[i]]);
    }
    system("pause");
    return 0;
}
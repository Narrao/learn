#include<stdio.h>
struct product
{
    int flag[20];//某一工序是否完成
    int endtime[20];//某一工序的结束时间
    int time[20];//某一工序所需时间
    int machinenum[20];//某一工序要用到的机器
};
struct machine
{
    int time[8000];//给每个机器创造时间线
};
int insert(struct product pro[],struct machine mech[],int num);//返回第num个工件下一个过程能够插入的开始时间
int anstime(struct product pro[],int n,int m);//通过找最大的结束时间找答案
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    struct machine mech[m+1];
    struct product pro[n+1];
    int process[n*m];
    //获取流程
    for(int i=0;i<n*m;i++)
    {
        scanf("%d",&process[i]);
    }
    //初始化并获取输入
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=8000;j++)
        {
            mech[i].time[j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pro[i].flag[j]=0;
            pro[i].endtime[j]=0;
            scanf("%d",&pro[i].machinenum[j]);
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&pro[i].time[j]);
        }
    }
    //按照步骤，找每个工件应该插入的时间并处理
    for(int i=0;i<n*m;i++)
    {
        int begin=insert(pro,mech,process[i]);

        //获取下一个工序数
        int k=1;
        while(pro[process[i]].flag[k])k++;

        pro[process[i]].flag[k]=1;
        pro[process[i]].endtime[k]=begin+pro[process[i]].time[k];

        //把时间占用掉
        for(int j=begin+1;j<=begin+pro[process[i]].time[k];j++)
        {
            mech[pro[process[i]].machinenum[k]].time[j]=process[i];
        }
    }
    int ans = anstime(pro,n,m);
    printf("%d",ans);
    system("pause");
    return 0;
}
int insert(struct product pro[],struct machine mech[],int num)
{
    //获取下一工序数
    int k=1;
    while (pro[num].flag[k])k++;
    //先通过上一工序的结束时间来确定下一工序最早的开始时间
    int begin=pro[num].endtime[k-1];
    if(k==1)
    {
        begin=0;
    }
    //判断是否能插入，直到能插入则退出循环
    int flag=0;
    while (!flag&&begin<8000)
    {
        if(mech[pro[num].machinenum[k]].time[begin+1]==0)
        {
            int i=1;
            for(;i<=pro[num].time[k];i++)
            {
                if(mech[pro[num].machinenum[k]].time[begin+i]!=0)break;
            }
            if(i==pro[num].time[k]+1)
            {
                flag=1;
            }
            else begin++;
        }
        else begin++;
    }
    return begin;
}
int anstime(struct product pro[],int n,int m)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(pro[i].endtime[m]>ans)ans=pro[i].endtime[m];
        }
    }
    return ans;
}
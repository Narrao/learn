/*输入n个学生的学号和3项成绩（假设成绩都是0~100的，不做额外检查），
计算每个学生的平均分（保留2位小数），并输出最高分的学号和平均成绩。
如果有相同的多个， 则输出多个。*/ 
#include <stdio.h>
int main()
{
    int n,t=-1;
    // float max;
    struct student
    {
        int num,a1,a2,a3;
        float ave;
    };
    scanf("%d",&n); 
    struct  student stu[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d%d",&stu[i].num,&stu[i].a1,&stu[i].a2,&stu[i].a3);
        stu[i].ave =(stu[i].a1 + stu[i].a2 + stu[i].a3) /3.0;
    //     if(stu[i].ave > max)
    //     {
    //         max = stu[i].ave;
    //         t = i;
    //     }
    }
    // 输出平均数
    for (int i = 0;i < n; i++)
    {
        printf("%.2f\n",stu[i].ave);
    }
    // for (int i = 0;i < n; i++)
    // {
    //     if (stu[i].ave == max)
    //     {
    //         printf("%d %.2f\n",stu[i].num,stu[i].ave);
    //     }
    // }
    return 0;
}
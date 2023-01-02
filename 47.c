#include <stdio.h>
#include <math.h>
int power(const char double_num[]);  //得到指数
int main()
{
    int p,flag=0; //p储存指数
    double ans=0,t=0.5; //t是二进制的权值
    char double_num[65];
    scanf("%s",&double_num);
    p = power(double_num);

    //算后52个二进制表示的小数部分
    for(int i = 12;i<=63;i++) 
    {
        ans=ans+(double_num[i]-48)*t;
        t=t/2;
    }
    ans=(1+ans)*pow(2,p);

    //输出
    if(double_num[0]=='1') printf("%.6lf",-ans);
    else printf("%.6lf",ans);
    return 0;
}
int power(const char double_num[])
{
    int num=0;
    for(int i=1;i<=11;i++)
    {
        num=num*2+double_num[i]-48;
    }
    return num-1023;
}
#include<stdio.h>
int legal(int year,int month,int day);
int days(int year ,int month,int day);
char month_char[13][10]={"","January","February","March","April", "May","June","July","August","September","October", "November","December"};
int main()
{
    int a, b, c,type1 = 0, type2 = 0;
    scanf("%d/%d/%d",&a,&b,&c);
    type1=legal(c,a,b);
    type2=legal(a,b,c);
    if(type1&&!type2)
    {
        printf("%s %d, %d",month_char[a],b,c+2000);
    }
    else if(type2&&!type1)
    {
        printf("%s %d, %d",month_char[b],c,a+2000);
    }
    else{
        int day=days(a,b,c)-days(c,a,b);
        if(day<0)day=-day;
        printf("%d",day);
    }
    system("pause");
    return 0;
}
int legal(int year,int month,int day)
{
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int flag = 1;
    year=year+2000;
    if(month>12||month<1)
    {
        flag=0;
    }
    else{
        if(year%4==0&&year%100!=0||year%400==0)
        {
            a[2]=29;
            if(day>a[month]||day<1)
            {
                flag=0;
            }
        }
        else{
            if(day>a[month]||day<1)
            {
                flag=0;
            }
        }
    }
    return flag;
}

int days(int year ,int month,int day)
{
    int days=0;
    year=year+2000;
    for (int  i = 2000; i<year; i++)
    {
        if(i%4==0&&i%100!=0||i%400==0)days=days+366;
        else days=days+365;
    }
    int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(year%4==0&&year%100!=0||year%400==0)a[2]=29;
    for(int i=1;i<month;i++)
    {
        days=days+a[i];
    }
    days=days+day;
    return days;
}
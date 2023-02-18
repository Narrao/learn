#include<stdio.h>
int main()
{
    int s,v,hour=8,min=0,time;
    scanf("%d%d",&s,&v);
    time=s/v+10;
    if(s%v!=0)time++;
    hour=hour-time/60;
    if(time%60!=0)hour--;
    if(hour<0)hour=hour+24;
    min=min-time%60;
    if(min<0)min=min+60;
    printf("%02d:%02d\n",hour,min);
    system("pause");
    return 0;
}
#include<stdio.h>
#define Pi 3.14
int main()
{
    int h,r,ans=0;
    scanf("%d%d",&h,&r);
    float volume;
    volume=Pi*r*r*h/1000;
    ans=20/volume+1;
    printf("%d",ans);
    system("pause");
    return 0;
}
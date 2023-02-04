#include<stdio.h>
int main()
{
    typedef union DOUBLE
    {
        double num;
        unsigned char ch[sizeof(double)];
    } dou;
    dou a;
    scanf("%lf",&a.num);
    int s[8];
    for(int i=sizeof(double)-1;i>=0;i--)
    {
        for(int j=0;j<8;j++)
        {
            s[j]=a.ch[i]%2;
            a.ch[i]=a.ch[i]/2;
        }
        for(int j=7;j>=0;j--)
        {
            printf("%d",s[j]);
        }
    }
    system("pause");
    return 0;
}
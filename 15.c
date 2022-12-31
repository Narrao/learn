#include <stdio.h>
double sqrt(double m);
int main()
{
    int n;
    double m;
    scanf("%d",&n);
    for(int i= 0;i < n;i++)
    {
        scanf("%lf",&m);
        if(m < 0)
        {
            printf("ERROR\n");
        }
        else if(m == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%.2f\n",sqrt(m));
        }
    }
    system("pause");
    return 0;
}
double sqrt(double m)
{
    double i,ans;
    for(i = 0;;i++)
    {
        if(i*i>m)break;
    }
    i = i - 1;
    ans = i * (1+(m-i*i)/i/i/2);
    return ans;
}
#include<stdio.h>
#include<math.h>
int main()
{
    int n,a,b,c;
    scanf("%d",&n);
    double p;
    for(int i = 0;i < n; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        p=(a+b+c)/2.0;
        if(a+b>c&&a+c>b&&b+c>a)
        {
            printf("%.2lf\n",sqrt(p*(p-a)*(p-b)*(p-c)));
        }else printf("error\n");
    }
    system("pause");
    return 0;
}
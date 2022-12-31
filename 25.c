#include<stdio.h>
int main()
{
    int n,i=0,sum=0,count=0,flag=1;
    char x,y;
    int a[1000]={0};
    scanf("%d",&n);
    getchar();
    while ((x=getchar())!='\n')
    {
        if(x=='-')flag=0;
        else if(x>='0'&&x<='9')
        {
            a[i]=a[i]*10+(int)x-48;
        }
        else if(y>='0'&&y<='9'&&!(x>='0'&&x<='9'))
        {
            if(flag==0)a[i]=-a[i];
            i++;
            flag=1;
        }
        y=x;
    }
    if(i==0)printf("n/a");
    else
    {
        for(int j =0;j<=i;j++)
        {
            sum=sum+a[j];
        }
        printf("%.2f",1.0*sum/(i+1));
    }
    system("pause");
    return 0;
}
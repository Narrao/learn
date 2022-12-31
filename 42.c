#include<stdio.h>
int main()
{
    int n,m,ans=0,flag=0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&m);
        if(m%3==0&&(ans==0||m<ans))
        {
            ans=m;
            flag=1;
        }
    }
    if(flag)
    {
        printf("%d",ans);
    }else{
        printf("Null");
    }
    system("pause");
    return 0;
}
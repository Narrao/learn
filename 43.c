#include<stdio.h>
int main()
{
    int n;
    char a[1000];
    char *p=a;
    scanf("%d",&n);
    int ans[n];
    for(int i = 0;i < n;i++)
    {
        int count=0;
        scanf("%s",a);
        int x=0,y=0;
        while(*(p+y)!=0)y++;
        y--;
        while (x<y)
        {
            if(*(p+x)!=*(p+y))count++;
            x++;
            y--;
        }
        if(count==1)ans[i]=1;
        else ans[i]=0;
    }
    for(int i=0;i<n;i++)printf("%s\n",ans[i]?"yes":"no");
    system("pause");
    return 0;
}
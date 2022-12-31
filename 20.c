#include<stdio.h>
int main()
{
    int n,flag;
    scanf("%d",&n);
    char a[1000];
    for(int i = 0;i < n;i++)
    {
        scanf("%s",a);
        flag=1;
        int b=0,c=0;
        while(a[c]!=0)c++;
        c--;
        while(b < c)
        {
            if(a[b]==a[c]){b++;c--;}
            else{flag=0;break;}
        }
        printf("%s\n",flag ? "Yes":"No");
    }
    system("pause");
    return 0;
}
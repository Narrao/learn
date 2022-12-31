#include<stdio.h>
int main()
{
    int n;
    char a;
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++)
    {
        scanf("%c",&a);
        getchar();
        if(a>='a'&&a<='z')a=a-32;
        printf("%c\n",a);
    }
    system("pause");
    return 0;
}
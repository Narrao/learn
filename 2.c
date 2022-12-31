// 将十进制数a转化成b进制
#include <stdio.h>
int main()
{
    int a,b,n,j = -1;
    int m[15];
    scanf("%d",&n);
    // n组数据
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&a,&b);
        if(a == 0)printf("0");
        while(a != 0)
        {
            j++;
            m[j] = a % b;
            a = a / b;
        }
        for(j;j >= 0;j--)
        {
            printf("%d",m[j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
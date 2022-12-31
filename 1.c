// 保留a/b的c位小数并四舍五入，c<=1000
#include <stdio.h>
int main()
{
    int a,b,c,n;
    int m[1002];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        // 整数部分
        m[0]=a/b;
        // 求c+1为小数
        for(int j = 0;j <= c;j++)
        {
            a = (a % b) * 10;
            m[j+1] = a / b;
        }
        if(m[c + 1] >= 5)
        {
            int i = c;
            m[i]++;
            // 四舍五入
            while(m[i] == 10&&i > 0)
            {
                m[i] = 0;
                m[i - 1]++;
                i--;
            }
        }
        printf("%d.",m[0]);
        for(int i = 1;i <= c;i++)
        {
            printf("%d",m[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
// 冒泡排序并出输出每次的处理结果
#include <stdio.h>
int main()
{
    int n,t;
    int num[100];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&num[i]);
    }
    for(int i = 0;i < n-1;i++)
    {
        for(int j = 0;j < n-i-1;j++)
        {
            if(num[j] > num[j + 1])
            {
                t = num[j];
                num[j] = num[j + 1];
                num[j + 1] = t;
            }
        }
        for(int m=0;m<n;m++)
        {
            printf("%d ",num[m]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
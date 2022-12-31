//插入排序并输出每次执行的结果
#include <stdio.h>
int main()
{
    int n,t,j;
    int num[100];
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&num[i]);
    }
    printf("%d\n",num[0]);
    for(int i = 1;i < n;i++)
    {
        t = num[i];
        j = i-1;
        while(t < num[j])
        {
            j--;
        }
        for(int m = i;m >j+1;m--)
        {
            num[m]=num[m - 1];
        }
        num[j+1] = t;
        // 输出结果
        for (int j = 0; j <= i; j++)
        {
            printf("%d ",num[j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
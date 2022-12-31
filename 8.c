// 约瑟夫问题
#include <stdio.h>
int main()
{
    int n,k,m,t = 0,count;
    int person[101];
    scanf("%d%d%d",&n,&k,&m);
    // 初始化存活的人为1
    for (int i = 1; i <= n; i++)
    {
        person[i] = 1;
    }
    count = n;
    while (count > 2)
    {
        // 判断人是否能报数
        if(person[k] == 1)
        {
            t = t % m + 1;
            // 若报到m的人为0
            if(t == m)
            {
                person[k] = 0;
                count--;
            }
        }
        k = k % n +1;
    }
    for (int i = 1; i <= n; i++)
    {
        if(person[i] == 1)
        printf("%d ",i);
    }
    system("pause");
    return 0;
}
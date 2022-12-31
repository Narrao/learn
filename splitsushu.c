// Editor 编辑器
//主函数
#include <stdio.h>
#include<math.h>
#include<stdlib.h>
int issushu(long a)
{
    for (long i = 2; i < sqrt(a); i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
        
    }
    return 1;
    
    
}
int main()
{
    //计算逻辑---算法
    //分解391为两个素数的积
    long sushu = 0,i=0,a=0,b=0 ,j = 0;
    printf("请输入素数：");
    scanf("%d",&sushu);
    printf("\n");
    //怎么设计算法
    for (long i = 2; i < sqrt(sushu); i++)
    {
        if (issushu(i) == 1)
        {
            a = i;
            b = sushu / a;
            if (issushu(b)==1 && a*b == sushu)
            {
                printf("%d可以分解为素数%d和%d的积\n",sushu,a,b);
                j=j+1;
            }
            
        }
        
    }
    if (j == 0)
    {
        printf("%d无法分解为两个素数\n",sushu);
    }
    else
        printf("找到%d个结果\n",j);
    
    system("pause");
    return 0;
}

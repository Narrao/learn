// 蛇形输出字符
#include <stdio.h>
int main()
{
    int m,n,count,row,col,t = -1,flag = 1;// t移动方向 flag是否转弯
    int num[101][101];
    scanf("%d%d",&m,&n);
    count = m * n;
    row = col = 1;
    num[row][col]=1;
    // 判断是否为单行
    if(m == 1)
    {
        for(int i = 1;i <= n;i++)
        {num[1][i]=i;}
    }
    else if(n == 1)
    {
        for(int i = 1;i <= m;i++)
        {num[i][1]=i;}
    }
    else
    {
        for (int i = 2; i <= count; i++)
        {   
            // 判断转弯的条件
            if(row == 1&&col ==n&&flag)
            {
                row++;
                flag = 0;
                t = -t;
                num[row][col]=i;
                continue;
            }
            else if(row == m&&col == 1&&flag)
            {
                col++;
                flag = 0;
                t = -t;
                num[row][col]=i;
                continue;
            }
            else if((row == 1||row == m)&&flag)
            {
                col++;
                flag = 0;
                t = -t;
                num[row][col]=i;
                continue;
            }
            else if((col == 1||col == n)&&flag)
            {
                row++;
                flag = 0;
                t = -t;
                num[row][col]=i;
                continue;
            }
            flag = 1;
            row = row + t;
            col = col - t;
            num[row][col]=i;
        }
    }
    // 输出得到的方阵
    for(int i = 1;i <=m ;i++ )
    {
        for(int j = 1;j <= n;j++)
        {
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
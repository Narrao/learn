#include<stdio.h>
# define max 10
int main (void)
{
    int a[max][max],n;//n表示矩阵个数
    scanf("%d",&n);
    char *ans[n];//指针数组，每个指针可以指向一个字符串用来存储答案
    int m,flag,k=0;//m表示矩阵的长宽,flag判断,k指向要存答案的ans下标
    for(int x=0;x<n;x++)
    {
        flag=1;
        scanf("%d",&m);
        //输入矩阵
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        //逐行判断
        for(int i=0;i<n;i++)
        {
            //判断右上角是否有0
            for(int j=i;j<n;j++)
            {
                if(a[i][j]==0)
                {
                    flag=0;
                    break;
                }
            }
            //判断左下角是否为0
            for(int j=0;j<i;j++)
            {
                if(a[i][j]!=0)
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag)ans[k++]="YES";
        else ans[k++]="NO";
    }
    for(int x=0;x<n;x++)printf("%s\n",ans[x]);
    system("pause");
    return 0;
}
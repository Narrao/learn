#include<stdio.h>
int main()
{
    int n,A,B;
    scanf("%d",&n);
    int a[n],b[n]; //b用来复制a可以更改
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int max=-1,sum,flag,position;
    //循环遍历
    for(A=1;A<=n;A++)
    {
        for(B=1;B<A;B++)
        {
            //初始化
            for(int i=0;i<n;i++) b[i]=a[i];
            sum=0;flag=1;position=0;
            while (1)
            {
                //移动位置
                if(flag) position=position+A;
                else position=position-B;
                //给分或溺死退出
                if(position==n-1) break;
                else if(position<0||position>=n||b[position]==-1)
                {
                    sum=-1;
                    break;
                }else{
                    sum=sum+b[position];
                    b[position]=-1;
                }
                //转换方向
                flag=1-flag;
            }
            if(sum>max) max=sum;
        }
    }
    printf("%d",max);
    system("pause");
    return 0;
}
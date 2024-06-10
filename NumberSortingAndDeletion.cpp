#include<stdio.h>

int main()
{
    int arr[260];
    int i,j,cnt=0;
    int x,k;
    while ((x=getchar())!='\n'&&x!=' ')
    {
        arr[cnt++]=x-48;
    }
    scanf("%d",&k);
    for(int i=0;i<cnt-1;i++)
    {
        for(int j=cnt-1;j>i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
    i=0;
    while(i<=cnt-1&&arr[i]=='0')i++;//处理前导0 
    if(i==cnt)printf("0");
    else
        for(j=i;j<=cnt-k-1;j++)
            printf("%d",arr[j]); 
    return 0;
}
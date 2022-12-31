#include<stdio.h>
void sort(int num[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int num[n];
    int k=0,sum=0;
    for(int i = 0;i < n;i++)scanf("%d",&num[i]);
    sort(num,n);
    for(int i = 0;i < n-1;i++)
    {
        k = k + num[i];
        sum = sum + k;
    }
    printf("%d",sum);
    // for(int i = 0;i < n;i++)printf("%d",num[i]);
    system("pause");
    return 0;
}
void sort(int num[],int n)
{
    int t,k;
    for(int i = 0;i < n-1;i++)
    {
        k = i;
        for(int j= i+1;j<n;j++)
        {
            if(num[j]<num[k])k=j;
        }
        if(i!=k)
        {
            t = num[i];
            num[i] = num[k];
            num[k] = t;
        }
    }
}
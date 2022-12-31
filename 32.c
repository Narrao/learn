#include<stdio.h>
#include<string.h>
void sort(int num[]);
int main()
{
    char a[10000];
    char *p=a;
    int num[27]={0};
    int m=26;
    long sum=0;
    scanf("%s",a);
    for(int i = 0;i < strlen(a);i++)
    {
        num[(int)*(p+i)-96]++;
    }
    sort(num);
    for(int i = 1;i<=26;i++)
    {
        for(int j = 0;j < num[i];j++)sum=sum+m;
        m--;
    }
    printf("%ld\n",sum);
    system("pause");
    return 0;
}
void sort(int num[])
{
    int t,k;
    for(int i = 1;i < 26;i++)
    {
        k = i;
        for(int j= i+1;j<=26;j++)
        {
            if(num[j]>num[k])k=j;
        }
        if(i!=k)
        {
            t = num[i];
            num[i] = num[k];
            num[k] = t;
        }
    }
}
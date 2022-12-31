#include<stdio.h>
int main()
{
    int a[10]={0};
    for(int i=0;i<10;i++)scanf("%d",&a[i]);
    for(int i=1;i<10;i++)
    {
        if(a[i]!=0)
        {
            printf("%d",i);
            a[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(a[i]!=0)
        {
            for (int j = 0; j < a[i]; j++)
            {
                printf("%d",i);
            }
            
        }
    }
    system("pause");
    return 0;
}
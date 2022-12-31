#include<stdio.h>
void print(char a,int n);
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m % 2 == 0)
        {
            printf("error\n");
        }else{
            printf("print\n");
            for(int j=1;j<=m;j++)
            {
                if(j<=(m+1)/2)
                {
                    print(' ',(m+1)/2-j);
                    print('*',2*j-1);
                    printf("\n");
                }
                else
                {
                    print(' ',j-(m+1)/2);
                    print('*',(m-j+1)*2-1);
                    printf("\n");
                }
            }
        }
    }
    system("pause");
    return 0;
}
void print(char a,int n)
{
    for(int i=0;i<n;i++)printf("%c",a);
}
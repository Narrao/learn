#include<stdio.h>
#define MAX 100
int main()
{

    char a[MAX]="";
    int b[MAX]={0},i=0,j=0,k=0;
    while((a[i]=getchar())!='\n')i++;
    while (1)
    {
        while (a[j]>='a'&&a[j]<='z'||a[j]>='A'&&a[j]<='Z')j++;
        for(int i=j-1;i>=k;i--)printf("%c",a[i]);
        while(!(a[j]>='a'&&a[j]<='z'||a[j]>='A'&&a[j]<='Z'))
        {
            if(a[j]=='\n')goto out;
            printf("%c",a[j]);
            j++;
        }
        k=j;
    }
out:    
    system("pause");
    return 0;
}
#include<stdio.h>
int main()
{
    struct book{
        char name[31];
        double prize;
    };
    int n;
    scanf("%d",&n);getchar();
    int max=0,min=0;
    struct book book[n];
    for(int i=0;i<n;i++)
    {
        char a;int k=0;
        while((a=getchar())!='\n')
        {
            book[i].name[k++]=a;
        }
        book[i].name[k]=0;
        scanf("%lf",&book[i].prize);
        if(book[i].prize>book[max].prize)max=i;
        if(book[i].prize<book[min].prize)min=i;
    }
    printf("%.2lf, %s\n%.2lf, %s",book[max].prize,book[max].name,book[min].prize,book[min].name);
}
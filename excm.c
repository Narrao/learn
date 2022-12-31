#include<stdio.h>
int main(void)
{
    int lower,upper,i;
    double celsius;
    scanf("%d %d",&lower, &upper);
    if(lower>upper||upper>100)
    {
       printf("Invalid.");
       lower=upper+1;
    }
    else
    {
        printf("fahr celsius\n");
        for(i=lower;i<=upper;i++)
        {
            celsius=5.0*(i-32.0)/9.0;
            printf("%4d%6.1f\n",i,celsius);
        }
    }
    getchar();getchar();
    return 0;
}
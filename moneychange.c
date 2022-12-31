//Enter an amount: 100.00
//With tax added: $105.00
#include <stdio.h>
#include<stdlib.h>
#define TAX 1.05
void main()
{
    float money=0;
    printf("Enter an amount:");
    scanf("%f",&money);
    printf("With tax added:%.02f\n",money*TAX);
    system("pause");
}
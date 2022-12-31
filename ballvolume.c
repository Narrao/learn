#include <stdio.h>
#include<stdlib.h>
#define PI 3.1415956535897932384626f
void main()
{
    float r=0;
    printf("请输入球的半径：");
    scanf("%f",&r);
    printf("球的体积是:%.02f\n",4.0f / 3.0f * PI * r * r * r);
    system("pause");
}
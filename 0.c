// 三个数排序
#include <stdio.h>
int main()
{
    int x,y,z,temp;
    scanf("%d%d%d",&x,&y,&z);
    temp = x;
    if(y > x && y > z)
    {
        x = y;
        y = temp;
    }
    else if(z > x && z > y)
    {
        x = z;
        z = temp;
    }
    temp = y;
    if(z > y)
    {
        y = z;
        z = temp;
    }
    printf("x=%d,y=%d,z=%d",x,y,z);
    system("pause");
    return 0;
}
#include<stdio.h>
int main()
{
    unsigned long ulsum = 0;
    unsigned long ulcount = 5;
    while (0 < ulcount)
    {
        ulsum += ulcount;
        ulcount--;
    }
    printf("%lu\n",ulsum);
    return 0;
}
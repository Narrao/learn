#include<stdio.h>
#include<string.h>
int main()
{
    char name[10];
    int var1 = 1,var2 = 2;
    printf("var1=%d,var2=%d\n",var1,var2);
    puts("Where do you live?");
    gets(name);
    printf("<%s> is length %d\n",name,strlen(name));
    printf("var1 = %d; var2 = %d\n",var1,var2);
    puts("OK");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int GS1 = 0,Group = 0,PUbilsher = 0,Item = 0,Check = 0;
    
    printf("Enter ISBN: ");

    scanf("%d-%d-%d-%d-%d",&GS1,&Group,&PUbilsher,&Item,&Check);

    printf("\nGs1 prefix: %d\nGroup indentifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",GS1,Group,PUbilsher,Item,Check);

    system("pause");
}
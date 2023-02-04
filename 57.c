#include<stdio.h>
#include<stdlib.h>
void re(char x,char y,int *a,int *b,int *c);
int main()
{
    char x,y;
    int a=0,b=0,c=0;
    while(scanf("%c:=%c;",&x,&y)==2)
    {
        re(x,y,&a,&b,&c);
    }
    
    printf("%d %d %d\n",a,b,c);
    system("pause");
    return 0;
}
void re(char x,char y,int *a,int *b,int *c)
{
    if(x=='a')
    {
        if(y>='0'&&y<='9')*a=atoi(&y);
        else if(y=='b')*a=*b;
        else if(y=='c')*a=*c;
    }else if(x=='b'){
        if(y>='0'&&y<='9')*b=atoi(&y);
        else if(y=='a')*b=*a;
        else if(y=='c')*b=*c;
    }else if(x=='c')
        if(y>='0'&&y<='9')*c=atoi(&y);
        else if(y=='a')*c=*a;
        else if(y=='b')*c=*b;
}
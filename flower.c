#include <stdio.h>
int main()
{
    float a;//a为输入的数 
    float b;//b用于储存a的小数部分 
    int c;//c用于储存a的整数部分  
    scanf ("%f",&a);
    c=a;
    if (a>=0)
      {
	  b=a-c;
      if (b>=0.5)
      printf ("%d",c+1);
      else 
      printf ("%d",c);
	  }
    else{
    b=c-a;
    if (b>=0.5)
    printf ("%d",c-1);
    else
    printf ("%d",c);
    }
    getchar();getchar(
    );
	return 0;
}

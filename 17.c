#include<stdio.h>
int main(void){
	int b,d,o;
	char ch;
	b=d=o=0;
	ch=getchar();
	while(ch!='\n'){
		switch(ch){
			case' ':
			b ++;break;
			case'0':case'1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':
				d++;break;
				default:
					o++;break;			
		}
        ch=getchar();
	}
	printf("blank = %d, digit = %d, other = %d",b,d,o);
system("pause");
return 0;	

}
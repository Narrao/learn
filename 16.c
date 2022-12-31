#include <stdio.h>
#include <math.h>
int main(void){
int a,b;
char c;
double x;
scanf("%d%d%s",&a,&b,&c);
if(b==90){
	if(c=='m'){
	x=a*6.95*(1-0.05);	
	}else{
		x=a*6.95*(1-0.03);
	}
}else if(b==93){
	if(c=='m'){
	x=a*7.44*(1-0.05);	
	}else{
		x=a*7.44*(1-0.03);
	}
}else{
		if(c=='m'){
	x=a*7.93*(1-0.05);	
	}else{
		x=a*7.93*(1-0.03);
	}
}
printf("%.2f",x);
	return 0;
}
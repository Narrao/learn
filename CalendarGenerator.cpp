#include<stdio.h>
#include<stdlib.h>
typedef char *string;
int isornotyear(void);
void thecalendar(int year);
void printmonth(int month,int year);
 string monthname(int month);
int blackspace1 (int year);
int days(int month,int year);
void printdays(int a ,int month, int year);
int main (void){
	int year;
	year=isornotyear();
	if(year==0) printf("Failure");
	else thecalendar(year);
    system("pause");
	return 0;
}

int isornotyear(void){
	int year;
	scanf("%d",&year);
	if(year>=1900) return year;
	return 0;
}
void thecalendar(int year){
	int month;
	void printmonth(int month,int year);
	for( month=1; month<=12; month++ ){
		printmonth(month,year);
		printf("\n");
	}
}
void printmonth(int month,int year){
	string monthname(int month);
	int blackspace1 (int year);
	void printdays(int a ,int month, int year);
	static int a;
	int i;
		printf("    %s %d\n",monthname(month),year);
		printf(" Su Mo Tu We Th Fr Sa\n");
		if(month==1){
			a=blackspace1(year);
			printdays(a , month, year);
		    
		} 
		else{
			a=(a+days(month-1,year))%7;
			printdays(a , month, year);
		}
	
}
string monthname(int month){
	switch (month) {
		case 1: return ("January");
		case 2: return ("February");
		case 3: return ("March");
		case 4: return ("April");
		case 5: return ("May");
		case 6: return ("June");
		case 7: return ("July");
		case 8: return ("August");
		case 9: return ("September");
		case 10: return ("October");
		case 11: return ("November");
		case 12: return ("December");
	}
}
int blackspace1 (int year){
	int a=1, i; 
    int sum=0;
	for(i=1900;i<=year-1;i++) {
		if(i%4==0&&i%100!=0||i%400==0) a=(a+366-1)%7+1;
		else a=(a+365-1)%7+1;
	}
	return a;
}
int days(int month,int year){
	switch(month){
		case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
		case 4: case 6: case 9: case 11: return 30;
		case 2: if(year%4==0&&year%100!=0||year%400==0) return 29;
		        else return 28;
	}
	 
}
void printdays(int a ,int month, int year){
	int i, day;
	int days(int month,int year);
	for(i=1;i<=a;i++) printf("   ");
	for(i=1;i<=7-a;i++) printf("%3d",i);
	printf("\n");
	for(day=i;day<=days(month,year);day++){
		printf("%3d",day);
		 if((a+day)%7==0) printf("\n");
	}
}

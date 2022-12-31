#include<stdio.h>
int c(int a);
int main()
{
	int n,count=0;
	int a[1025];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		count = count +c(a[i]);
	}
	printf("%s",(count%2)?"Alice":"Bob");
	system("pause");
	return 0;
}
int c( const int a)
{
	int count=0,b=a;
	while (b%2==0)
	{
		count++;
		b=b/2;
	}
	return count;
}
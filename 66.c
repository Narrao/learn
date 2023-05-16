#include <stdio.h>
int min(const int a[],int first,int last);
int main()
{
	int a[250]={0},b[250]={0},n;
	char x;
	int len=0;
	while((x=getchar())>='0'&&x<='9')a[len++]=x-48;
	scanf("%d",&n);
	n=len-n;
	int count=0;
	while(count!=n)
	{
		if(count!=0)
		{
			b[count]=min(a,b[count-1]+1,len-n+count);	
		}else{
			b[count]=min(a,0,len-n+count);
		}
		
		count++;
	}
	int flag=0;
	for(int i=0;i<n;i++)
	{
		if(a[b[i]]!=0||flag==1)
		{
			printf("%d",a[b[i]]);
			flag=1;
		}
	}
	if(flag==0)printf("0");
	return 0;
}
int min(const int a[],int first,int last)
{
	int min=10,ans=-1;
	for(int i=first;i<=last;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
			ans=i;	
		}
	}
	return ans;
}

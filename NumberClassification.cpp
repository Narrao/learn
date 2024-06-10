#include <iostream>
using namespace std;
int main()
{
	int n,x;
	cin>>n>>x;
	int left=0,right=0,same=0;
	bool flag=false;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		if(temp>x)right++;
		else if(temp<x)left++;
		else if(temp==x&&flag==false)flag=true;
		else if(temp==x&&flag==true)same++;
		
	}
	if(same>0)
	{
		for(int i=0;i<same;i++)
		{
			if(left>=right)right++;
			else left++;
		}
	}
	if(flag&&(left==right||left+1==right))cout<<0;
	else if(flag&&left>right)cout<<left-right;
	else if(flag&&left<right)cout<<right-left-1;
	else if(!flag&&(left==right||left+1==right))cout<<1;
	else if(!flag&&left>right)cout<<left-right+1;
	else if(!flag&&left<right)cout<<right-left;
    return 0;
}
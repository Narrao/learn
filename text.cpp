#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int dtob(int x,int n,int m,int a[]);
int ok(int x,int n,int m,int a[]);
int main()
{
    const int N=22;
    int n,m,sum,ans=0,a[N],f[10000]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        sum+=a[i]; 
    }
    for(int i=0;i<pow(2,n);i++)
    {
        f[dtob(i,n,m,a)]=1;
    }
    for(int i=1;i<10000;i++)
    {
        if(f[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
int ok(int x,int n,int m,int a[])
{
    int ans=0,c[n]={0};
    int i=n-1;
    int out=0;
    while (x!=0)
    {
        c[i--]=x%2;
        ans=ans+x%2;
        x=x/2;
    }
    if(ans==n-m)
    {
        for(int i=0;i<n;i++)
        {
            out=out+c[i]*a[i];
        }
    }else out=0;
    return 0;
}
int dtob(int x,int n,int m,int a[])
{
    int ans=0,c[n]={0};
    int i=n-1;
    int out=0;
    while (x!=0)
    {
        c[i--]=x%2;
        ans=ans+x%2;
        x=x/2;
    }
    if(ans==n-m)
    {
        for(int i=0;i<n;i++)
        {
            out=out+c[i]*a[i];
        }
    }else out=0;
    return 0;
}
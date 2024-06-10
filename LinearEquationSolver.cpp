#include <bits/stdc++.h>
using namespace std;
int main()
{
    string commend,temp_s,x;
    int equl,num1[100]={0},num2[100]={0},flag1,flag2,count1=0,count2=0,x1[100]={0},x2[100]={0},a=0,b=0;
    cin>>commend;
    for(int i=0;i<commend.length();i++)if(commend[i]=='='){equl=i;break;}
    for(int i=0;i<commend.length();i++)if((commend[i]<'0'||commend[i]>'9')&&commend[i]!='-'&&commend[i]!='+'&&commend[i]!='=')
    {
        x=commend.substr(i,1);
        break;
    }
    int num=0,temp=0;
    for (int i = 0; i < commend.length(); i++)
    {
        if(commend[i]>='0'&&commend[i]<='9')
        {
            if(num==0)
            {
                temp=i;
                num++;
            }else{
                num++;
            }
        }else if((commend[i]=='-'||commend[i]=='='||commend[i]=='+')&&(commend[i-1]>='0'&&commend[i-1]<='9'))
        {
            if(commend[temp-1]=='+'||temp==0||commend[temp-1]=='=')
            {
                temp_s=commend.substr(temp,num);
                num1[count1]=atoi(temp_s.c_str());
                x1[count1]=temp;
                count1++;
                num=0;
            }else{
                temp_s=commend.substr(temp,num);
                num1[count1]=-atoi(temp_s.c_str());
                x1[count1]=temp;
                count1++;
                num=0;
            }
        }else if(commend.substr(i,1)==x){
            if(commend[i-1]=='+'||i==0||commend[i-1]=='=')
            {
                num2[count2]=1;
                x2[count2]=temp;
                count2++;
            }
            else if(commend[i-1]=='-')
            {
                num2[count2]=-1;
                x2[count2]=temp;
                count2++;
            }
            else if(commend[temp-1]=='+'||temp==0||commend[temp-1]=='=')
            {
                temp_s=commend.substr(temp,num);
                num2[count2]=atoi(temp_s.c_str());
                x2[count2]=temp;
                count2++;
                num=0;
            }else{
                temp_s=commend.substr(temp,num);
                num2[count2]=-atoi(temp_s.c_str());
                x2[count2]=temp;
                count2++;
                num=0;
            }
        }
    }
    if(commend[commend.length()-1]>='0'&&commend[commend.length()-1]<='9')
    {
        if(commend[temp-1]=='+'||temp==0||commend[temp-1]=='=')
            {
                temp_s=commend.substr(temp,num);
                num1[count1]=atoi(temp_s.c_str());
                x1[count1]=temp;
                count1++;
                num=0;
            }else{
                temp_s=commend.substr(temp,num);
                num1[count1]=-atoi(temp_s.c_str());
                x1[count1]=temp;
                count1++;
                num=0;
            }
    }
    for(int i=0;i<count1;i++)
    {
        if(x1[i]<equl)
        {
            a=a-num1[i];
        }else{
            a=a+num1[i];
        }
    }
    for(int i=0;i<count2;i++)
    {
        if(x2[i]<equl)
        {
            b=b+num2[i];
        }else{
            b=b-num2[i];
        }
    }
    cout<<x<<'=';
    printf("%.3f",a*1.0/b);
    system("pause");
    return 0;
}
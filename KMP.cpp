#include<iostream>
#include<string>
using namespace std;
void get_next(string sub,int* next)
{
    int i = 0, j = -1;
    next[0] = -1;
    while(i<sub.length())
    {
        if(j == -1 || sub[i] == sub[j]){i++;j++;next[i]=j;}
        else
            j = next[j];
    }
}
int KMP(string s,string sub){
    int next[sub.length()];
    get_next(sub,next);
    int i = 0,j = 0;
    while(i<int(s.length())&&j<int(sub.length()))
    {
        if(j==-1||s[i] == sub[j]){
            i++;j++;
        }else{
            j = next[j];
        }
    }
    if(j>=int(sub.length()))return i;
    else return -1;
}
int main()
{
    string s,sub;
    cin>>s>>sub;
    int index = KMP(s,sub);
    cout <<index;
    system("pause");
    return 0;
}
#include <cstdio>
#include <cstring>
const int MAXN = 12;

int main()
{
    char s[MAXN];
    int mp[26];
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    for(int i=0;i<26;i++)mp[i]=i;
    char ch1, ch2;
    for (int i = 0; i < m; i++)
    {
        scanf(" %c %c", &ch1, &ch2);
        for(int j=0;j<26;j++)
        {
            if(mp[j]==int(ch1)-97)mp[j]=int(ch2)-97;
            else if(mp[j]==int(ch2)-97)mp[j]=int(ch1)-97;
        }
    }

    // 遍历字符串，根据映射表进行字符替换
    for (int i = 0; i < n; i++)
    {
        if (mp[s[i]-97] !=s[i]-97) // 如果当前字符有映射关系，则进行替换
            s[i] = mp[s[i]-97]+97;
    }

    printf("%s\n", s);

    return 0;
}
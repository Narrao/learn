#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    int key;
    string origin;
    string secret;
    cout << "输入密钥：";
    cin >> key;
    cout << "输入要加入的内容：";
    cin >> origin;
    for (int i = 0; i < origin.length(); i++)
    {
        secret += (origin[i]-'a'+key)%26+'a';
    }
    fstream file;
    file.open("secret.txt", ios::out);
    file << key << endl;
    file << secret;
    file.close();
    cout << "密文为：" << secret << endl;

    origin = "";
    file.open("secret.txt", ios::in);
    file >> key;
    file >> secret;
    file.close();
    for(int i=0; i < secret.length(); i++)
    {
        origin += (secret[i]-'a'-key+26)%26+'a';
    }
    cout << "原文为：" << origin << endl;
    system("pause");
    return 0;
}
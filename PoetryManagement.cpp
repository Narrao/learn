#include <iostream>
#include <fstream>
#include <string>
#include <list>
using namespace std;
class poetry {
protected:
    string name;
    string type;
    string author;
    string content;
public:
    poetry();
    poetry(string name,string type,string author,string content);
    void print();
    bool operator==(string x);
    char* getstr();
    friend istream& operator>>(istream& is,poetry& p);
};

poetry::poetry() {}
poetry::poetry(std::string name, std::string type, std::string author, std::string content) {
    this->name = name;
    this->type = type;
    this->author = author;
    this->content = content;
}
void poetry::print() {
    std::cout<<this->name<<" "<<this->type<<" "<<this->author<<std::endl<<this->content<<std::endl;
}
bool poetry::operator==(std::string x) {
    if(this->name==x)return true;
    else if(this->type==x)return true;
    else if(this->author==x)return true;
    else if(this->content==x)return true;
    else return false;
}

char* poetry::getstr() {
    char* str=new char[100];
    strcpy(str,this->name.c_str());
    strcat(str," ");
    strcat(str,this->type.c_str());
    strcat(str," ");
    strcat(str,this->author.c_str());
    strcat(str," ");
    strcat(str,this->content.c_str());
    return str;
}

std::istream& operator>>(std::istream& is,poetry& p) {
    cout<<"诗名：";
    is>>p.name;
    cout<<"类型：";
    is>>p.type;
    cout<<"作者：";
    is>>p.author;
    cout<<"内容：";
    is>>p.content;
    return is;
}


void menu();
int main() {
    list<poetry> poem;
    int choice;
    fstream file;
    file.open("poetry.txt",ios::in);
    if(file.fail())
    {
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    while(!file.eof())
    {
        //读取诗歌到链表

        string name, author, content, type;
        file >> name >> author >> type >> content;
        poetry p(name, type, author, content);
        poem.push_back(p);
    }
    file.close();
    while(1)
    {
        menu();
        cout<<"请输入你的操作：";
        cin>>choice;
        switch (choice) {
            case 1:
            {
                poetry p;
                cin>>p;
                poem.push_back(p);
                break;
            }
            case 2:
            {
                cout<<"请输入要查找的诗歌信息：";
                string x;
                cin>>x;
                list<poetry>::iterator it;
                for( it=poem.begin();it!=poem.end();it++)
                {
                    if(*it==x)
                    {
                        it->print();
                        break;
                    }
                }
                if(it==poem.end()) cout<<"没有找到这首诗"<<endl;
                break;
            }
            case 3:
            {
                cout<<"请输入要删除的诗歌信息：";
                string x;
                cin>>x;
                list<poetry>::iterator it;
                for( it=poem.begin();it!=poem.end();it++)
                {
                    if(*it==x)
                    {
                        poem.erase(it);
                        cout<<"已成功删除此诗"<<endl;
                        break;
                    }
                }
                if(it==poem.end()) cout<<"没有找到这首诗"<<endl;
                break;
            }
            case 4:
            {
                list<poetry>::iterator it=poem.begin();
                for(it;it!=poem.end();it++)
                {
                    it->print();
                }
                break;
            }
            case 5:
            {
                poem.clear();
                break;
            }
            case 6:
            {
                file.open("poetry.txt",ios::out);
                if(file.fail())
                {
                    cout<<"文件打开失败"<<endl;
                    return 0;
                }else{
                    list<poetry>::iterator it=poem.begin();
                    for(it;it!=poem.end();it++)
                    {
                        file.write((char*)it->getstr(),sizeof(poetry));
                    }
                    file.close();
                    cout<<"保存成功"<<endl;
                }
                break;
            }
            case 7:
            {
                return 0;
            }
        }
    }

    return 0;
}

void menu()
{
    cout<<"1.录入诗歌"<<endl;
    cout<<"2.查找诗歌"<<endl;
    cout<<"3.删除诗歌"<<endl;
    cout<<"4.输出所有诗歌"<<endl;
    cout<<"5.清空所有诗歌"<<endl;
    cout<<"6.保存诗歌到文件"<<endl;
    cout<<"7.退出"<<endl;
}
#include <string>
#include <iostream>

class table
{
	public:
		table();
        table(std::string name,std::string number,std::string home);
        void print();
        bool operator==(std::string name);
	protected:
        std::string name;
        std::string number;
        std::string home;
};

table::table()
{

}
table::table(std::string name, std::string number, std::string home) {
    this->name = name;
    this->number = number;
    this->home = home;
}

bool table::operator==(std::string name) {
    if(this->name==name)return true;
    else return false;
}
void table::print() {
    std::cout<<this->name<<" "<<this->number<<" "<<this->home<<std::endl;
}

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;
void menu();
int main() {
    char x = ' ';
    //创建一个tab容器
    list<table> tab;
    while (1) {
        menu();
        cout << "请输入操作：";
        cin >> x;
        if (x == '1') {
            string a, b, c;
            cin >> a >> b >> c;
            tab.push_front(table(a, b, c));
        } else if (x == '2') {
            //根据名字删除
            string a;
            cin >> a;
            list<table>::iterator it;
            it = find(tab.begin(), tab.end(), a);
            if (it != tab.end()) {
                tab.erase(it);
            } else {
                cout << "查无此人" << endl;
            }
        } else if (x == '3') {
            //根据名字查找并输出
            string a;
            cin >> a;
            list<table>::iterator it;
            it = find(tab.begin(), tab.end(), a);
            if (it != tab.end()) {
                it->print();
            } else {
                cout << "查无此人" << endl;
            }
        } else if (x == '4') {
            //输出所有
            list<table>::iterator it;
            for (it = tab.begin(); it != tab.end(); it++) {
                it->print();
            }
        } else if (x == '5')break;
        else cout << "输入错误" << endl;
    }
    cout << "退出成功";
    return 0;
}
void menu() {
    cout << "***************************\n";
    cout << "*                         *\n";
    cout << "*          1.插入          *\n";
    cout << "*          2.删除          *\n";
    cout << "*          3.查询          *\n";
    cout << "*          4.输出          *\n";
    cout << "*          5.退出          *\n";
    cout << "***************************\n";
}
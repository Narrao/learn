#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<map>
using namespace std;
class stu{
    private:
        string name;
        int num;
    public:
        stu():name("null"),num(0){};
        stu(string n,int m):name(n),num(m){};
        void show()
        {
            cout<<name<<'\t'<<num<<endl;
        }
        bool operator==(const stu &s)
        {
            if(this->name==s.name&&this->num==s.num)
                return true;
            else return false;
        }
        bool operator<(const stu &s)
        {
            if(this->num<s.num)
                return true;
            else return false;
        }
};

void menu();

int main()
{
    map<string,list<stu>> course;
    map<string,int> coursenum;
    course["C++"]=list<stu>();
    course["Python"]=list<stu>();
    course["Java"]=list<stu>();
    course["Html"]=list<stu>();
    course["Css"]=list<stu>();
    coursenum["C++"]=10;
    coursenum["Python"]=10;
    coursenum["Java"]=10;
    coursenum["Html"]=10;
    coursenum["Css"]=10;
    while(1)
    {
        menu();
        int x=-1;
        cout << "请输入操作：";
        cin>>x;
        string coursename,name;int num,number;
        switch(x){
            case 1:
                cout<<"输入要插入学生的课程名:";
                cin>>coursename;
                cout<<"输入要插入学生的姓名和学号:";
                cin>>name>>num;
                if (course[coursename].size() < coursenum[coursename])
                    course[coursename].push_back(stu(name, num));
                else
                    cout << "该课程已满，无法插入更多学生。" << endl;
                break;
            case 2:
                cout<<"输入要查询学生的课程名:";
                cin>>coursename;
                cout<<"输入要查询学生的姓名和学号:";
                cin>>name>>num;
                if(find(course[coursename].begin(),course[coursename].end(),stu(name,num))==course[coursename].end())
                    cout<<"该学生不在该课程中。"<<endl;
                else
                    cout<<"该学生在该课程中。"<<endl;
                break;
            case 3:
                cout<<"输入要删除学生的课程名:";
                cin>>coursename;
                cout<<"输入要删除学生的姓名和学号:";
                cin>>name>>num;
                if(find(course[coursename].begin(),course[coursename].end(),stu(name,num))==course[coursename].end())
                    cout<<"该学生不在该课程中。"<<endl;
                else
                {
                    course[coursename].remove(stu(name,num));
                    cout<<"删除成功。"<<endl;
                }
                break;
            case 4:
                cout<<"输入要扩展容量的课程名:";
                cin>>coursename;
                cout<<"输入要扩展的容量:";
                cin>>number;
                coursenum[coursename]+=number;
                cout<<"扩展成功。"<<endl;
                break;
            case 5:
                cout<<"输入要清空的课程名:";
                cin>>coursename;
                course[coursename].clear();
                cout<<"清空成功。"<<endl;
                break;
            case 6:
                cout<<"输入要排序的课程名:";
                cin>>coursename;
                course[coursename].sort();
                cout<<"排序成功。"<<endl;
                break;
            case 7:
                cout<<"输入要显示的课程名:";
                cin>>coursename;
                if(course[coursename].empty())
                    cout<<"该课程为空。"<<endl;
                else
                    cout<<"姓名\t学号"<<endl;
                for(auto i:course[coursename])
                    i.show();
                break;
            case 8:
                cout<<"退出成功。"<<endl;
                return 0;
            default:
                cout<<"输入错误。"<<endl;
                return 0;
        }
    }
    system("pause");
    return 0;
}

//显示菜单
void menu() {
    cout << "****************************\n";
    cout << "*          1.插入          *\n";
    cout << "*          2.查找          *\n";
    cout << "*          3.删除          *\n";
    cout << "*          4.扩展容量      *\n";
    cout << "*          5.清空          *\n";
    cout << "*          6.按学号排序    *\n";
    cout << "*          7.显示选课情况  *\n";
    cout << "*          8.退出          *\n";
    cout << "****************************\n";
}
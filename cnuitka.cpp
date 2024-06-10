#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(int argc, char* argv[]) {
    string order= "nuitka --mingw64 --onefile --standalone  --show-progress --output-dir=.\\ ";
    string filename;
    for (int i = 1; i < argc; ++i) {
        if(strcmp(argv[i],"-n")==0)
        {
            order = order + "--windows-disable-console ";
        }
        else if(strcmp(argv[i],"-p")==0)
        {
            if (i + 1 < argc) {
                order += "--enable-plugin=" + std::string(argv[i + 1]) + " ";
                ++i;  // Skip the next argument
            } else {
                std::cout << "Error: Missing argument for -p option" << std::endl;
                return 1;
            }
        }
        else if(strcmp(argv[i],"--help")==0)
        {
            cout<<"Usage: cnuitka [options] filename"<<endl;
            cout<<"Options:"<<endl;
            cout<<"-n: Disable console"<<endl;
            cout<<"-p: Enable plugin"<<endl;
            cout<<"--help: Show help"<<endl;
            return 0;
        }
        else
        {
            if(filename.empty())
            {
                filename = argv[i];
            }
            else
            {
                cout<<"Error: Too many files"<<endl;
                return 1;
            }
        }
    }
    if(filename.empty())
    {
        cout<<"Error: No file"<<endl;
        return 1;
    }
    order = order + filename;
    system(order.c_str());
    int begin = filename.find_last_of("\\");
    int end = filename.find_last_of(".");
    string name = filename.substr(begin+1,end-begin-1);
    string name1=name+".dist";
    string name2=name+".build";
    string name3=name+".onefile-build";
    string del = "rmdir /s /q .\\"+name1;
    system(del.c_str());
    del = "rmdir /s /q .\\"+name2;
    system(del.c_str());
    del = "rmdir /s /q .\\"+name3;
    system(del.c_str());
    return 0;
}

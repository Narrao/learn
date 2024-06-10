#include"fraction.hpp"
#include<iostream>
#include<cassert>
using namespace std;

int main(){
    fraction f1;
    fraction f2(1,2);
    f2.display();
    fraction f3(2,-3);
    fraction f4(f2);
    f4.display();
    // Arithmetical operators: + - * /
    fraction f5=f2.operator+(f3);
    cout<< "f2+f3=";
    f5.display();
    fraction f6=f2.operator-(f3);
    cout<< "f2-f3=";
    f6.display();
    fraction f7=f2.operator*(f3);
    cout<< "f2*f3=";
    f7.display();
    fraction f8=f2.operator/(f3);
    cout<< "f2/f3=";
    f8.display();
    //关系运算符
    cout<<"f2<f3 "<<f2.operator<(f3)<<endl;
    cout<<"f2<=f3 "<<f2.operator<=(f3)<<endl;
    cout<<"f2==f3 "<<f2.operator==(f3)<<endl;
    cout<<"f2!=f3 "<<f2.operator!=(f3)<<endl;
    cout<<"f2>=f3 "<<f2.operator>=(f3)<<endl;
    cout<<"f2>f3 "<<f2.operator>(f3)<<endl;
    cout<<f3.operator double()<<endl;
    cout<<f3.operator string()<<endl;

    //将字符串的十进制小数转换成分数
    fraction f9=fraction::fromDecimalString("1.414");
    cout<<"f9 is ";
    f9.display();

    // 检查流提取运算符
    istringstream iss("3/4");
    fraction f10;
    iss >> f10; // 使用流提取运算符
    // 检查分数是否正确
    f10.display();
    assert(f10.getNumerator() == 3);
    assert(f10.getDenominator() == 4);
    cout << "流提取运算符正确" << endl;

    // 检查流插入运算符
    ostringstream oss;
    oss << f2; // 使用流插入运算符
    // 检查输出是否正确
    string expected = "1/2";
    assert(oss.str() == expected);
    cout << "流插入运算符正确" << endl;
    system("pause");
    return 0;
}


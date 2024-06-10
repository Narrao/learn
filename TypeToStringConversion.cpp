#include <sstream>
#include <string>
#include <iostream>
using namespace std;
template <typename T>
string toString(T value)
{
    ostringstream os;
    os << value;
    return os.str();
}
template <typename T>
T toType(string str)
{
    T value;
    istringstream is(str);
    is >> value;
    return value;
}
int main()
{
    string str = "123";
    int a = toType<int>(str);
    cout << a << endl;
    double pi = 3.1415926;
    string str2 = toString<double>(pi);
    cout << str2 << endl;
    return 0;
}
#include<iostream>
using namespace std;
class TriangeleException : public exception
{
public:
    const char *what() const throw()
    {
        return "这三边不能构成三角形";
    }
};
class Triangle
{
private:
    int a, b, c;
public:
    Triangle(int a, int b, int c)
    {
        if (a + b <= c || a + c <= b || b + c <= a)
        {
            throw TriangeleException();
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int getC()
    {
        return c;
    }
};
int main()
{
    int a, b, c;
    cout << "请输入三角形的三边长：" << endl;
    cin >> a >> b >> c;
    try
    {
        Triangle t(a, b, c);
        cout << "周长为：" << t.getA() + t.getB() + t.getC() << endl;
    }
    catch (TriangeleException &e)
    {
        cout << e.what() << endl;
    }
    catch (exception &e)
    {
        cout<<"其他异常"<<endl;
        cout << e.what() << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;
// 矩阵类Matrix的声明
class Matrix
{
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix &m);
    ~Matrix();
    Matrix &operator=(const Matrix &m);      // 赋值运算符重载
    Matrix operator+(const Matrix &m) const; // 加法运算符重载
    Matrix operator-(const Matrix &m) const; // 减法运算符重载
    int &operator()(int i, int j);           // 下标运算符重载
    int getRows() const;                     // 取行数
    int getCols() const;                     // 取列数
private:
    int rows; // 行数
    int cols; // 列数
    int *p;   // 指向动态分配的二维数组的指针
};
// 矩阵类Matrix的实现
int &Matrix::operator()(int i, int j)
{
    return p[i * cols + j];
}
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols)
{
    p = new int[rows * cols];
}
Matrix::Matrix(const Matrix &m) : rows(m.rows), cols(m.cols)
{
    p = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        p[i] = m.p[i];
    }
}
Matrix::~Matrix()
{
    delete[] p;
}
Matrix &Matrix::operator=(const Matrix &m)
{

    delete[] p;
    rows = m.rows;
    cols = m.cols;
    p = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        p[i] = m.p[i];
    }
    return *this;
}
int Matrix::getRows() const
{
    return rows;
}
int Matrix::getCols() const
{
    return cols;
}
Matrix Matrix::operator+(const Matrix &m) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
    {
        result.p[i] = p[i] + m.p[i];
    }
    return result;
}
Matrix Matrix::operator-(const Matrix &m) const
{
    Matrix result(rows, cols);
    for (int i = 0; i < rows * cols; i++)
    {
        result.p[i] = p[i]-m.p[i];
    }
    return result;
}

// 测试程序
int main()
{
    Matrix a(5, 5);
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            a(i, j) = i * a.getCols() + j;
        }
    }
    // 输出矩阵a的值
    cout<<"矩阵a的值：\n";
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            cout<<a(i, j)<<"\t";
        }
        cout<<endl;
    }
    Matrix b(a);
    // 输出矩阵b的值
    cout<<"矩阵b的值：\n";
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            cout<<b(i, j)<<"\t";
        }
        cout<<endl;
    }
    a(2, 3) = 100;
    
    cout<<"a(2,3)=100之后的值：\n";
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            cout<<a(i, j)<<"\t";
        }
        cout<<endl;
    }
    a = a + b;
    cout<<"a = a + b之后的值：\n";
    for (int i = 0; i < a.getRows(); i++)
    {
        for (int j = 0; j < a.getCols(); j++)
        {
            cout<<a(i, j)<<"\t";
        }
        cout<<endl;
    }
    b = b - a;
    cout<<"b = b - a之后的值：\n";
    for (int i = 0; i < b.getRows(); i++)
    {
        for (int j = 0; j < b.getCols(); j++)
        {
            cout<<b(i, j)<<"\t";
        }
        cout<<endl;
    }
    return 0;
}



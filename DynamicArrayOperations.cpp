#include <iostream>
using namespace std;
template <typename Type>
class List
{
private:
    Type *data ;
    int length;
    int MaxSize;
public:
    List(int size = 50)
    {
        data = new Type[size];
        length = size;
        MaxSize = size;
    }
    //从顺序表中删除具有最小值的元素并由函数返回被删元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。
    Type DeleteMin()
    {
        if (length == 0)
        {
            cout << "顺序表为空" << endl;
            exit(0);
        }
        int min = data[0];
        int minIndex = 0;
        for (int i = 1; i < length; i++)
        {
            if (data[i] < min)
            {
                min = data[i];
                minIndex = i;
            }
        }
        data[minIndex] = data[length - 1];
        length--;
        return min;
    }
    //从顺序表中删除第i个元素并由函数返回被删元素的值。如果i不合理或顺序表为空则显示出错信息并退出运行
    Type Delete(int i)
    {
        if (i < 1 || i > length)
        {
            cout << "删除位置不合理" << endl;
            exit(0);
        }
        Type temp = data[i - 1];
        for (int j = i; j < length; j++)
        {
            data[j - 1] = data[j];
        }
        length--;
        return temp;
    }
    // 向顺序表中第i个位置插入一个新的元素x。如果i不合理则显示出错信息并退出运行
    void Insert(int i, Type x)
    {
        if (length == MaxSize)
        {
            cout << "顺序表已满" << endl;
            exit(0);
        }
        if (i < 1 || i > length + 1)
        {
            cout << "插入位置不合理" << endl;
            exit(0);
        }
        for (int j = length; j >= i; j--)
        {
            data[j] = data[j - 1];
        }
        data[i - 1] = x;
        length++;
    }
    // 从顺序表中删除具有给定值x的所有元素
    void DeleteValue(Type x)
    {
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            if (data[i] != x)
            {
                data[k] = data[i];
                k++;
            }
        }
        length = k;
    }
    //  从顺序表中删除其值在给定值s与t之间 (要求s小于t) 的所有元素，如果s或t不合理或顺序表为空则显示出错信息并退出运行。
    void DeleteRange(Type s, Type t)
    {
        if (s >= t)
        {
            cout << "s应小于t" << endl;
            exit(0);
        }
        if (length == 0)
        {
            cout << "顺序表为空" << endl;
            exit(0);
        }
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            if (data[i] < s || data[i] > t)
            {
                data[k] = data[i];
                k++;
            }
        }
        length = k;
    }
    // 从有序顺序表中删除其值在给定值s与t之间（要求s<t）的所有元素，如果s或t不合理或顺序表为空则显示出错信息并退出运行
    void DeleteRange2(Type s, Type t)
    {
        if (s >= t)
        {
            cout << "s应小于t" << endl;
            exit(0);
        }
        if (length == 0)
        {
            cout << "顺序表为空" << endl;
            exit(0);
        }
        int k = 0;
        for (int i = 0; i < length; i++)
        {
            if (data[i] >= s && data[i] <= t)
            {
                k++;
            }
            else
            {
                data[i - k] = data[i];
            }
        }
        length -= k;
    }
    // 将两个有序顺序表合并成一个新的有序顺序表并由函数返回结果顺序表。
    void MergeList(List &la, List &lb)
    {
        int i = 0, j = 0, k = 0;
        while (i < la.length && j < lb.length)
        {
            if (la.data[i] < lb.data[j])
            {
                data[k] = la.data[i];
                i++;
                k++;
            }
            else
            {
                data[k] = lb.data[j];
                j++;
                k++;
            }
        }
        while (i < la.length)
        {
            data[k] = la.data[i];
            i++;
            k++;
        }
        while (j < lb.length)
        {
            data[k] = lb.data[j];
            j++;
            k++;
        }
        length = k;
    }
    // 从顺序表中删除所有其值重复的元素，使表中所有元素的值均不相同
    void DeleteSame()
    {
        int k = 0;
        for (int i = 1; i < length; i++)
        {
            if (data[i] != data[k])
            {
                data[++k] = data[i];
            }
        }
        length = k + 1;
    }

};
int main()
{
    system("pause");
    return 0;
}

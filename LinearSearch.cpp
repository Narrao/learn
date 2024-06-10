// 顺序查找
#include<iostream>
#include<vector>
using namespace std;
// 顺序查找类
class LinearSearch
{
    private:
        vector<int> data; // 数据
    public:
        LinearSearch(vector<int> a)
        {
            data = a;
        }
        int Search(int key) // 查找
        {
            int i;
            int n = data.size();
            for(i = 0; i < n; i++)
            {
                if(data[i] == key)
                    return i;
            }
            return -1;
        
        }
};
int main()
{
    // 输入数组
    vector<int> a;
    cout << "请输入数组元素，以-1结束" << endl;
    int temp;
    cin >> temp;
    while(temp != -1)
    {
        a.push_back(temp);
        cin >> temp;
    }

    // 输入要查找的元素
    cout << "请输入要查找的元素" << endl;
    int key;
    cin >> key;

    // 查找
    LinearSearch ls(a);
    int result = ls.Search(key);
    if(result == -1)
        cout << "查找失败" << endl;
    else
        cout << "查找成功，元素下标为" << result << endl;

    system("pause");
    return 0;
}
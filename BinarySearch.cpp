// 二分查找
#include<iostream>
#include<vector>
using namespace std;
// 二分查找类
class BinarySearch
{
    private:
        vector<int> data; // 数据
    public:
        BinarySearch(vector<int> a)
        {
            data = a; // 初始化
        }
        int Search(int key) // 查找
        {
            int left = 0;
            int right = data.size() - 1;
            int mid;
            while(left <= right)
            {
                mid = (left + right) / 2;
                if(data[mid] == key)
                    return mid;
                else if(data[mid] > key)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return -1;
        }
};
int main()
{
    // 输入数组
    vector<int> a;
    cout << "请输入有序的数组元素，以-1结束" << endl;
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
    BinarySearch bs(a);
    int result = bs.Search(key);
    if(result == -1)
        cout << "查找失败" << endl;
    else
        cout << "查找成功，元素下标为" << result << endl;
        
    system("pause");
    return 0;
}
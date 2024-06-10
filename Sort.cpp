#include<iostream>
#include<vector>
using namespace std;
class Sort
{
public:
    // 折半插入排序
    void binaryInsertSort(vector<int> &v)
    {
        for(int i = 1;i<v.size();i++)
        {
            int temp = v[i];
            int low = 0;
            int high = i-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(v[mid]>temp)
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            for(int j = i-1;j>=high+1;j--)
            {
                v[j+1]=v[j];
            }
            v[high+1]=temp;
        }
    }
    // 希尔排序
    void shellSort(vector<int>& v)
    {
        int n = v.size();
        int gap = n/2;
        while(gap>=1)
        {
            for(int i = gap;i<n;i++)
            {
                int temp = v[i];
                int j = i-gap;
                while(j>=0 && v[j]>temp)
                {
                    v[j+gap] = v[j];
                    j-=gap;
                }
                v[j+gap] = temp;
            }
            gap/=2;
        }
    }
    // 冒泡排序
    void bubbleSort(vector<int>& v)
    {
        int n = v.size();
        for(int i = 0;i<n-1;i++)
        {
            for(int j = 0;j<n-1-i;j++)
            {
                if(v[j]>v[j+1])
                {
                    int temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }
    }
    // 快速排序
    void quickSort(vector<int>& v,int left,int right)
    {
        if(left>=right) return;
        int i=left,j=right;
        int temp = v[left];
        while(i<j)
        {
            while(i<j && v[j]>=temp) j--;
            if(i<j)
            {
                v[i] = v[j];
                i++;
            }
            while(i<j && v[i]<=temp) i++;
            if(i<j)
            {
                v[j] = v[i];
                j--;
            }
        }
        v[i] = temp;
        quickSort(v,left,i-1);
        quickSort(v,i+1,right);
    }
    // 堆排序
    void heapSort(vector<int>& v)
    {
        int n = v.size();
        for(int i = n/2-1;i>=0;i--)
        {
            adjustHeap(v,i,n);
        }
        for(int i = n-1;i>=0;i--)
        {
            int temp = v[0];
            v[0] = v[i];
            v[i] = temp;
            adjustHeap(v,0,i);
        }
    }
    void adjustHeap(vector<int>& v,int i,int n)
    {
        int temp = v[i];
        for(int j = 2*i+1;j<n;j=2*j+1)
        {
            if(j+1<n && v[j]<v[j+1])
            {
                j++;
            }
            if(v[j]>temp)
            {
                v[i] = v[j];
                i = j;
            }
            else
            {
                break;
            }
        }
        v[i] = temp;
    }
};
int main()
{
    int n=8;
    vector<int> v={49,38,65,97,76,13,27,49};
    cout<<"原始数据：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    Sort s;
    s.binaryInsertSort(v);
    cout<<endl<<"折半插入排序：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    v={49,38,65,97,76,13,27,49};
    s.shellSort(v);
    cout<<endl<<"希尔排序：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    v={49,38,65,97,76,13,27,49};
    s.bubbleSort(v);
    cout<<endl<<"冒泡排序：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    v={49,38,65,97,76,13,27,49};
    s.quickSort(v,0,n-1);
    cout<<endl<<"快速排序：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    v={49,38,65,97,76,13,27,49};
    s.heapSort(v);
    cout<<endl<<"堆排序：";
    for(int i = 0;i<n;i++){
        cout<<v[i]<<' ';
    }
    system("pause");
    return 0;
}
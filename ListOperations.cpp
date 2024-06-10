#include <list>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
    //初始化一个list
    list<int> ls = {2,8,5,6,9,1,3,4,7};
    
    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    //查找5
    list<int>::iterator it = find(ls.begin(), ls.end(), 5);
    if(it!=ls.end())
    {
        cout << "find 5" << endl;
    }
    //降序
    ls.sort(greater<int>());
    
    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    //升序
    ls.sort();
    
    for (list<int>::iterator it = ls.begin(); it != ls.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    system("pause");
}
#include <iostream>
using namespace std;
#include <vector>
template<class T>
class Array {
private:
	vector<T> m_array;

public:
	Array(T array[], int len) {
		for (int i = 0; i < len; i++) {
			m_array.push_back(array[i]);
		}
	}

	void Myfind(T element) {
		int count = 0;
		for (int i = 0; i < m_array.size(); i++) {
			if (element = m_array[i]) {
				cout << "数组中有" << element << "这个元素，下标为：" << i << endl;
				count++;
			}
		}
		if (count == 0) {
			cout << "数组中没有这个元素。" << endl;
		}
		else {
			cout << "找完了，数组中共有" << count << "个该元素。" << endl;
		}
	}

	void Mysort() {
		for (int i = 0; i < m_array.size() - 1; i++) {
			for (int j = 0; j < m_array.size() - i - 1; j++) {
				if (m_array[j] < m_array[j + 1]) {
					T temp = m_array[j];
					m_array[j] = m_array[j + 1];
					m_array[j + 1] = temp;
				}
			}
		}
	}

	void Myinsert(T element, int pos) {
		vector<T>::iterator it = m_array.begin();
		it += pos;
		m_array.insert(it, element);
	}

	void printArray() {
		for (vector<T>::iterator it = m_array.begin(); it != m_array.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}


};

int main() {
	//int型数组测试
	int array1[8] = { 2,5,1,8,3,4,6,8 };
	int len = sizeof(array1) / sizeof(array1[0]);
	Array<int> arr1(array1, len);
	//1.查找
	int element1 = 8;
	arr1.Myfind(element1);
	//2.插值
	int element2 = 9;
	int pos = 3;
	cout << "插值前数组为：" << endl;
	arr1.printArray();
	arr1.Myinsert(element2, pos);
	cout << "插值后数组为：" << endl;
	arr1.printArray();
	//3.排序
	cout << "排序前数组为：" << endl;
	arr1.printArray();
	arr1.Mysort();
	cout << "排序后数组为：" << endl;
	arr1.printArray();

	//double型数组测试
	double array2[8] = { 2.30,5.13,1.46,8.28,3.57,4.98,6.39,8.26 };
	int len = sizeof(array2) / sizeof(array2[0]);
	Array<double> arr2(array2, len);
	//1.查找
	double element3 = 8.28;
	arr1.Myfind(element3);
	//2.插值
	double element4 = 9.612;
	int pos = 3;
	cout << "插值前数组为：" << endl;
	arr2.printArray();
	arr2.Myinsert(element4, pos);
	cout << "插值后数组为：" << endl;
	arr2.printArray();
	//3.排序
	cout << "排序前数组为：" << endl;
	arr2.printArray();
	arr2.Mysort();
	cout << "排序后数组为：" << endl;
	arr2.printArray();
	system("pause");
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const vector<T>& vec) { //編寫print函式，印出結果
	for (auto e : vec)
		std::cout << e << " ";
	std::cout << endl;
}

template <typename T>
void Swap(T& a, T& b) { //編寫兩兩元素交換的方法
	T t = a;
	a = b;
	b = t;
}

template <typename T>
void bubble_sort(vector<T> & a) { //編寫氣泡排序
	for (int i = a.size() - 1; i > 0; i--) {
		bool swaped = false; //先建立bool類型的變數
		for (int j = 0; j < i; j++)
			if (a[j + 1] < a[j]) {
				Swap(a[j], a[j + 1]);
				swaped = true; //當有交換發生，將swaped改為true
			}
				
		print(a);
		if (!swaped) break; //若這次迴圈沒有交換到，代表之後的元素已排序好，可以直接退出迴圈
	}
}

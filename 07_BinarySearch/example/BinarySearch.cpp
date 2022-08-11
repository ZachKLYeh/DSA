#include <vector>
#include <iostream>
using namespace std;

int C = 0; //計算搜尋自數次數
template<typename T, typename keyT, typename Function>
int linear_search(const vector <T>& vec, keyT key, Function fun) { //設立待搜尋的資料、關鍵字、條件的函數
	for (int i = 0; i < vec.size(); i++)
		if (fun(vec[i], key)) return i; //待搜尋的資料與關鍵字是否一樣
	return -1; //表示搜尋失敗
}
template<typename T, typename keyT>
bool Equal(T value, keyT key) { //建立比較函示判斷資料與關鍵字是否一致
	C++;
	return value == key;
}

template<typename T, typename keyT, typename Function>
int binary_search(const vector <T>& vec, keyT key, Function fun) {
	int low = 0; int high = vec.size() - 1; //定義第一個元素和最後一個元素的下標位置
	while (low <= high) { //表示存在此區間
		auto mid = (low + high) / 2;
		auto ret= fun(key,vec[mid]);
		if (ret == 0)return mid;
		else if (ret <= 0) { //說明關鍵字小於待搜尋元素
			high = mid - 1; //須更改下標
		}
		else {
			low = mid + 1;
		}
	}
	return -1;
}
template<typename T, typename keyT>
int Compare(keyT key,T value) { //同樣建立比較函式
	C++;
	return key-value;
}
int main() {
	vector<int> v{ 82,33,64,8,19,26,52 };
	C = 0;
	int ret = binary_search(v, 26, Compare<int, int>); 
	if (ret >= 0)std::cout << "搜尋的關鍵字：" << 26 << " 位置下標：" << ret << endl;
	else std::cout << "搜尋失敗\n";
	std::cout << "二分法比較次數：" << C << std::endl;

	C = 0;
	ret = linear_search(v, 26, Equal<int, int>);
	std::cout << "線性法比較次數：" << C << std::endl;
	
	return 0;
}
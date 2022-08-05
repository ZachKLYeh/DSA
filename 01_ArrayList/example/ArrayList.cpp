#include<iostream>
#include "ArrayList.hpp"

int main() { //編寫主程式
	SqlList<char> list; //建立SqlList的變量，數據元素類型設為字元(char)
	char ch;
	if (!list.get(1, ch))std::cout << "沒有找到 \n"; //箭頭方向"<<"是一個運算子。
	else std::cout << ch << std::endl;  //endl就是這一行到這邊結束換下一行(只能輸出，不能輸入)。
	list.push_back('A'); print(list);
	list.push_back('B'); print(list);
	list.push_back('C'); print(list);
	list.push_back('D'); print(list);
	list.set(2, 'E'); print(list);
	list.insert(3, 'F'); print(list);
	list.remove(3); print(list);
	list.pop_back(); print(list);
	list.remove_front(); print(list);

	int i = list.find(1, 'C');
	if (i >= 0) std::cout << "查找成功，位置是：" << i << std::endl;

	list.insert(2, 'A'); 
	list.push_back('A'); print(list);

	
	for (int p = 1; p < list.size();) {
		int i = list.find(p, 'A');
		if (i >= 0) std::cout << "查找成功，位置是：" << i << std::endl;
		p = i + 1;
	}
	
};

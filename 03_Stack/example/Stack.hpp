template<typename T>
class SqlStack {
	T* data, * top_; //建立指針變量T指向元素，及top_指向堆疊的位置
	int capacity;

public:
	SqlStack(int cap = 3) {
		data = new T[cap];
		if (!data) { top_ = 0; capacity = 0; return; } //創建失敗的情況
		top_ = data; capacity = cap; //創建成功的條件
	}
	T& top() { //編寫top()檢查堆疊是否為空的，並返回T類型的引用變量
		if (top_ == data) throw "堆疊為空";
		return *(top_ - 1);
	}
	bool push(T e) { //編寫push()函式，且容量也會隨資料的增加變多
		if (top_ - data == capacity) {
			T* p = new T[2 * capacity];
			if (!p) return false;
			for (int i = 0; i < capacity; i++)
				p[i] = data[i];
			delete[] data; data = p;
			top_ = data + capacity;
			capacity = 2 * capacity;
		}
		*top_ = e; top_++; return true;
	}
	bool pop() { //編寫pop()函示，需先判對堆疊是否為空
		if (top_ == data) return false;
		top_--; return true;
	}
	bool empty() { //檢查堆疊是不是空的，與top()相同概念
		return top_ == data;
	}
	void clear() { //清除堆疊所有元素
		top_ == data;
	}
};
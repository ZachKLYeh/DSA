template<typename T>
class LinkList {
	struct LNode //建立左節點結構
	{
		T data;
		LNode* next; //指向下一個元素的指針變量
	};
	LNode* head; //指向最前端的指針變量
public:
	LinkList() { //創建空的鏈結串列，並對head指針初始化
		head = new LNode();
		head->next = 0;
	}
	bool get(int i, T e) { //讀取鏈結串列的資料
		if (i <= 0) return false; //i結點小於0則錯誤
		LNode* p = head;  
		int j = 0; //j為現在訪問的元素
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!p) return false; //如果p是空指針則錯誤
		e = p->data; return true; //如果p找到i號節點的數據，則放入引用變量e
	}
	bool set(int i, T e) { //修改鏈結串列的資料，和get概念類似
		if (i <= 0) return false; 
		LNode* p = head;
		int j = 0; 
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!p) return false; 
		p->data = e; return true;
	}
	bool insert(int i, T e) { //插入元素至節點內
		if (i <= 0) return false;
		LNode* p = head;
		int j = 0;
		while (p && j < i-1) {
			p = p->next;
			j++;
		}
		if (!p) return false;
		LNode* s = new LNode(); //s為臨時的指針變量，存放新插入的元素
		s->data = e;
		s->next = p->next; //使p指向修改後的新節點
		p->next = s;
		return true;
	}
	bool remove(int i) { //刪除節點的函式，原理和insert相似
		if (i <= 0) return false;
		LNode* p = head;
		int j = 0;
		while (p && j < i) {
			p = p->next;
			j++;
		}
		if (!p) return false;
		LNode* q = p->next;
		p->next = q->next; 
		delete q;
		return true;
	}
	bool insert_front(T e) { //插入節點在鏈結串列最前端
		LNode* s = new LNode(); 
		if (!s) return false;
		s->data = e;
		s->next = head->next; 
		head->next = s;
		return true;
	}
	bool remove_front() { //刪除第一個節點
		LNode* q = head->next;
		head->next = q->next;
		delete q;
		return true;
	}
	bool push_back(T e) { //插入節點在鏈結串列最末端
		LNode* p = head;
		while (p->next)
			p = p->next;
		p->next = new LNode();
		if (!p->next) return false;
		p->next->next = 0; //p->next表示現在的尾節點，而p->next的下一個節點要成為新的尾節點
		p->next->data = e; //同時要把資料放進去
		return true;
	}
	void traverse(void (*fp)(T& e)) { //編寫遍歷操作，fp為函數指針，對p指向的data進行處理
		LNode* p = head->next;
		while (p) {
			fp(p->data);
			p = p->next;
		}
	}
};

#include<iostream>
template<typename T>
void Print(T &ch) {
	std::cout << ch << " ";
};
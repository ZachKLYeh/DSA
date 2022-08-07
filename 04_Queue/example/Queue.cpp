#include<iostream>
using namespace std;

template<class T> class Queue {
	struct Node { //設立節點前端和後端指標
		T data;
		Node* next;
	};
	Node* front_;
	Node* rear;

public: //宣告函式
	Queue();
	bool push(T e);
	bool pop();
	T& front() { //查詢位在前端指標的資料
		if (front_ == rear) throw"佇列為空";
		return front_->next->data;
	}
	bool empty() {
		return front_ == rear;
	}
};

template<class T>
Queue<T>::Queue() { //初始化佇列
	front_ = rear = new Node();
	if (!front_) throw "No Memory";
	front_->next = 0;
}

template<class T> 
bool Queue<T>::push(T e) { //將資料新增置後端指標
	Node* p = new Node;
	if (!p)return false;
	p->data = e; p->next = 0;
	rear->next = p;
	rear = p;
	return true;
}
template<class T>
bool Queue<T>::pop() { // 將資料從前端指標刪除
	if (front_ == rear) return false;
	Node* p = front_->next;
	front_->next = p->next;
	if (rear == p) rear = front_;
	delete p;
	return true;
}

int main() {
	Queue<int> Q;
	Q.push(12); 
	Q.push(3); 
	Q.push(6); 
	std::cout << Q.front() << std::endl;
	Q.pop();
	std::cout << Q.front() << std::endl << std::endl;

	Q.push(30);
	Q.push(16);
	while (!Q.empty()) {
		std::cout << Q.front() << std::endl;
		Q.pop();
	}
}
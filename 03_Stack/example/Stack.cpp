#include<iostream>
#include<string>
#include "Stack.hpp"
using std::string;

int main(){
	SqlStack<char> S;
	S.push('A'); //push元素
	S.push('B');
	S.push('C');
	S.push('D');
	while (!S.empty()) { //pop元素直到堆疊為空
		char e = S.top();
		std::cout << e << " ";
		S.pop();
	}

	SqlStack<string> S2;
	S2.push("Jason");
	S2.push("Allen");
	S2.push("Chris");
	while (!S2.empty()) { //pop元素直到堆疊為空
		string e = S2.top();
		std::cout << e << " ";
		S2.pop();
	}

};
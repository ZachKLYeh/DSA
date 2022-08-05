#include <string>
#include <iostream>
#include "LinkedList.hpp"

int main(){
	LinkList<char> list;
	list.push_back('A'); 
	list.traverse(Print); 
	std::cout << std::endl;
	list.push_back('B'); 
	list.traverse(Print); 
	std::cout << std::endl;
	list.insert_front('C'); list.traverse(Print); std::cout << std::endl;
	list.insert_front('D'); list.traverse(Print); std::cout << std::endl;
	list.insert(3,'E'); list.traverse(Print); std::cout << std::endl;
	list.set(2, 'F'); list.traverse(Print); std::cout << std::endl;
};
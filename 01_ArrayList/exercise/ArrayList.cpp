#include<iostream>
#include "ArrayList.hpp"

int main() {
    ArrayList<char> list;
    list.push_back('1');
    list.push_back('2');
    list.push_back('3');
    list.push_back('4');
    list.push_back('5');
    list.print_list();
    std::cout << "pop back two elements" << std::endl;
    list.pop_back();
    list.pop_back();
    list.print_list();
    std::cout << "get the 1st element" << std::endl;
    list.delete_element(1);
    list.print_list();
    std::cout << "insert number 2 at index 1" << std::endl;
    list.insert_element(1, '2');
    list.print_list();
    std::cout << "find index of element 3" << std::endl;
    list.find_index('3');
}
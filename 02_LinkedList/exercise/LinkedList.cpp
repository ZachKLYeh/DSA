#include <iostream>
#include "LinkedList.hpp"

int main() {
    LinkedList<int> list;
    std::cout << "Push back 5 elements:\n";
    list.PushBack(5);
    list.PushBack(4);
    list.PushBack(3);
    list.PushBack(2);
    list.PushBack(1);
    list.Print();

    std::cout << "Insert 4 at index 2:\n";
    list.Insert(2, 4);
    list.Print();

    std::cout << "Delete element at index 2:\n";
    list.Delete(2);
    list.Print();

    std::cout << "Reverse the linked list:\n";
    list.Reverse();
    list.Print();

    std::cout << "Get the element at index 4:\n";
    std::cout << list.Get(4) << "\n";

    std::cout << "Set the element at index 4 to 11:\n";
    list.Set(4, 11);
    list.Print();

    LinkedList<char> charlist;
    std::cout << "Push back 5 elements:\n";
    charlist.PushBack('A');
    charlist.PushBack('B');
    charlist.PushBack('C');
    charlist.PushBack('D');
    charlist.PushBack('E');
    charlist.Print();

    std::cout << "Insert F at index 2:\n";
    charlist.Insert(2, 'F');
    charlist.Print();

    std::cout << "Delete element at index 2:\n";
    charlist.Delete(2);
    charlist.Print();

    std::cout << "Reverse the linked list:\n";
    charlist.Reverse();
    charlist.Print();

    std::cout << "Get the element at index 4:\n";
    std::cout << charlist.Get(4) << "\n";

    std::cout << "Set the element at index 4 to F:\n";
    charlist.Set(4, 'F');
    charlist.Print();

}
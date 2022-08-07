#include <iostream>
#include "Queue.hpp"

int main() {
    Queue<int> Q;
    std::cout << "push 3 elements\n";
    Q.Push(3);
    Q.Push(4);
    Q.Push(5);
    Q.Print(); 
    std::cout << "pop 1 element\n";
    Q.Pop();
    Q.Print();
    std::cout << "Is the Queue empty?";
    Q.Empty();
    std::cout << "pop 2 elements\n";
    Q.Pop();
    Q.Pop();
    std::cout << "Is the Queue empty?";
    Q.Empty();
    std::cout << "pop 1 element\n";
    Q.Pop();
}
#include<iostream>
#include "Stack.hpp"

int main() {
    Stack<int> stack;
    std::cout << "Push 5 elements:\n";
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.Print();

    std::cout << "Is the stack empty?\n";
    stack.Empty();

    std::cout << "Pop 2 elements:\n";
    stack.Pop();
    stack.Pop();
    stack.Print();

    std::cout << "Is the stack empty?\n";
    stack.Empty();

    std::cout << "Clear the stack\n";
    stack.Clear();
    std::cout << "Is the stack empty?\n";
    stack.Empty();
}
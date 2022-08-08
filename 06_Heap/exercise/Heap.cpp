#include <iostream>
#include "Heap.hpp"

int main() {
    std::cout << "Binary min heap:\n";
    MinHeap heap(10);
    std::cout << "insert 8 elements into heap, each insert include a upadjust:\n";
    heap.InsertKey(23);
    heap.InsertKey(16);
    heap.InsertKey(38);
    heap.InsertKey(12);
    heap.InsertKey(83);
    heap.InsertKey(5);
    heap.InsertKey(34);
    heap.InsertKey(67);
    heap.Print();
    std::cout << "Decrease index 3(which is 23) to value 3, each decrease include a downadjust:\n";
    heap.DecreaseKey(3, 3);
    heap.Print();
    std::cout << "Extract min element:" << heap.ExtractMin() << "\n";
    heap.Print();
    std::cout << "Delete element at index 1(which is 16), each delete include a decrease+extract:\n";
    heap.DeleteKey(1);
    heap.Print();

    std::cout << "Heap Sort:\n";
    std::cout << "Original array:\n228, 134, 354, 236, 73, 21234, 3434\n\n";
    int array[] = {228, 134, 354, 236, 73, 21234, 3434};
    int size = sizeof(array)/sizeof(array[0]);
    std::cout << "Heap sorted:\n";
    HeapSort(array, size);

    PriorityQueue Q;
    std::cout << "Priority Queue:\n" << "Push 3 elements:";
    Q.Push(3);
    Q.Push(2);
    Q.Push(1);
    Q.Print();
    std::cout << "Queue size:" << Q.Size() << "\n";
    std::cout << "Pop min element(1):";
    Q.Pop();
    Q.Print(); 
    std::cout << "Pop min element(2):";
    Q.Pop();
    Q.Print(); 
    std::cout << "Pop min element(3):";
    Q.Pop();
    Q.Print(); 
    std::cout << "Queue size:" << Q.Size() << "\n";

}
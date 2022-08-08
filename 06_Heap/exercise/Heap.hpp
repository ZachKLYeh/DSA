/*
Binary heap is like a binary tree, 
but it is complete tree and has order to the node structure.

MinHeap: The minimun element reside in the root, 
each parent node has value smaller then it's child node

Why do we need heap?
Heap is a method used to accomplish priority queue, heap sort, etc...

A binary heap is typically represented as array.
We can get the parent, left child and right via simple index operation
Arr[(i-1)/2]	Returns the parent node
Arr[(2*i)+1]	Returns the left child node
Arr[(2*i)+2]	Returns the right child node

we are building a int heap, thus key is equal to element

example heap
            1   
         /     \
        2       3
      /   \   /   \
      4   5   6   7

saved as:
index:  0, 1, 2, 3, 4, 5, 6
data:  {1, 2, 3, 4, 5, 6, 7}

Heapify:
Heapify a mess heap will be really costy, so we implement heap orginazation
by keeping insertion in order by bottom up branch operation.
And when extracting root, we use top down brahch operation.
The wholy heapify fucntion does not exist. 
Because the insertion will not make a mess heap.

1. buttom up:
only heapify on a single branch, for operation on leaf element
2. top down
for operation on root, or on a misindex large element
*/
#include <climits>

class MinHeap {
private:
    int capacity; // capacity of heap array

public:
    int* data; // pointer to the array head element
    int heap_size; // current number of heap elements

    MinHeap(int cap = 10) {
        heap_size = 0;
        capacity = cap;
        data = new int[capacity];
    }

    void Swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    bool PowerOfTwo(int x) {return !(x == 0) && !(x & (x - 1));}

    int LChild(int i) {return (2 * i) + 1;}

    int RChild(int i) {return (2 * i) + 2;}

    int Parent(int i) {return (i - 1) / 2;}

    // up adjust from position i, used in insertion and decrease
    void UpAdjust(int i) {
        while (i != 0 && data[Parent(i)] > data[i]) {
            Swap(data[Parent(i)], data[i]);
            i = Parent(i);
        }
    }

    // down adjust from position i, used in extraction
    void DownAdjust(int i) {
        int l = LChild(i); //index of lchild
        int r = RChild(i); //index of rchild
        int min = i;
        if (l < heap_size && data[i] > data[l]) {
            min = l;
        }
        if (r < heap_size && data[min] > data[r]) {
            min = r;
        }
        if (min != i) {
            Swap(data[min], data[i]);
            DownAdjust(min);
        }
    }

    void InsertKey(int k) {
        if (heap_size == capacity) {
            std::cout << "\nExceed capacity, cannot insert\n";
            return;
        }
        // insert the new key to the end
        data[heap_size] = k;
        int i = heap_size;
        heap_size++;
        // this is not heapify!!!It can only work when you are inserting
        // which find the position of a key on its own branch
        UpAdjust(i);
    }

    // since the key is decreased, we only need to do buttom up operation to keep heap
    void DecreaseKey(int i, int value) {
        data[i] = value;
        UpAdjust(i);
    }

    int ExtractMin() {
        if (heap_size == 0) return INT_MAX;
        int root = data[0];
        data[0] = data[heap_size-1];
        //replace the root element with the last elemet in data[]
        heap_size--;
        //then readjust the heap, only root is not in order, we use down adjust to find its position
        DownAdjust(0);
        return root;
    }

    void DeleteKey(int i) {
        //change the key to minimun
        data[i] = INT_MIN;
        //the key must appear in the root
        UpAdjust(i);
        //extract the root(min) element
        ExtractMin();
    }

    void Print() {
        for (int i = 0; i < heap_size; i++) {
            if (PowerOfTwo(i+1)) {
                std::cout << "\n";
            }
            std::cout << data[i] << "  ";
        }
        std::cout << "\n\n";
    }

};

void HeapSort(int array[], int size) {
    MinHeap heap[size];
    for (int i = 0; i < size; i++) {
        heap->InsertKey(array[i]);
    }
    for (int i = 0; i < size; i++) {
        std::cout << heap->ExtractMin() << "  ";
    }
    std::cout << "\n\n";
};

class PriorityQueue {
private:

public:
    MinHeap heap[100];

    PriorityQueue() {
    }
    void Push(int i) {
        heap->InsertKey(i);
    }

    void Pop() {
        heap->ExtractMin();
    }

    int Top() {
        return heap->data[0];
    }

    int Size() {
        return heap->heap_size;
    }

    void Print() {
        heap->Print();
    }

};
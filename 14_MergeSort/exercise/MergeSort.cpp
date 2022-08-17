/*
Merge Sort is also a recurssive sorting algorithm
It is done by merging two sorted vectors into one sorted vectors

1. split the vector into small sub vectors (1 or 2 elements)
2. merge the small sub vectors, merge order is based on split order!!
3. merge all

{5, 4, 3, 2, 1}
{5, 4, 3}{2, 1}
{5, 4}{3}{2}{1}
{5}{4}{3}{2}{1}
{4, 5}{3}{2}{1}
{3, 4, 5}{1, 2}
{1, 2, 3, 4, 5}
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Print(vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << "  ";
    cout << "\n";
}

// Merge function is used to merge two sorted arrays into one
template<typename T>
void Merge(vector<T>& data, int head, int middle, int tail){
    // create a new vector to store output
    // because this is not done by swapping
    vector<T> output(data);
    int i = head, j = middle+1, k = head;
    // case1: two vectors still have elements to be merged
    while(i <= middle && j <= tail) {
        if (data[i] < data[j]) output[k++] = data[i++];
        else output[k++] = data[j++];
    }
    // case2: only first vector have elements left
    while (i <= middle) output[k++] = data[i++];
    // case3: only second vector have elements left
    while(j <= tail) output[k++] = data[j++];
    data = output;
}

template<typename T>
void _MergeSort(vector<T>& vec, int head, int tail) {
    if (head == tail) return; // end condition
    _MergeSort(vec, head, (head + tail) / 2);
    _MergeSort(vec, (head + tail) / 2 + 1, tail);
    Merge(vec, head, (head + tail)/ 2, tail);
    Print(vec);
}

template<typename T>
void MergeSort(vector<T>& vec){
    int head = 0;
    int tail = vec.size() - 1;
    _MergeSort(vec, head, tail);
}

int main() {
    vector<int> vec = {113, 23, 4, 2134, 24, 24, 336, 1, 26, 52, 136, 266};
    MergeSort(vec);
}


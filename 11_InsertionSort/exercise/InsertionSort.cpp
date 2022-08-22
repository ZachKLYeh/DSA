/*
Insertion sort:
1. divide the original array into sorted and unsorted part
2. at each iteration, extract an element from unsorted array
3. move the sorted array and leave a empty index
4. insert the extrated element into empty index

array: 3, 2, 1

1. first, i = 1, j = 9
j  i
3, 2, 1

2. key = vector[i], 
j  i
3, 2, 1   (key = 2)

3. if vec[j] > key, it means we need to move foward, otherwise, stop here to insert
   vec[j](3) is larger than key(2), we move vec[j](3) to vec[j+1](2)

j  i
3, 3, 1

4. j--

j  j+1  i
     3, 3, 1

5. insert key to j+1 location

j+1  i 
  2, 3, 1
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Display(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "  " ;
    }
    cout << "\n";
}

template<typename T>
void InsertionSort(vector<T>& vec) {    
    for (int i = 1; i < vec.size(); i++) { // i is the boundary of sorted and unsorted array
        
        T key = vec[i]; // key is the first unsorted element
        int j = i - 1; // j is the cursor in sorted array

        while (j >= 0 && vec[j] > key) {
            // j'th element is larger then the unsorted element
            // move up the index
            vec[j+1] = vec[j];
            j--;
        }
        // until key < vec[i] we find the location to insert the unsorted element
        vec[j+1] = key;
        Display(vec);
    }
}

int main() {
    vector<int> vec = {23, 13, 423, 3456, 12, 543, 2, 3544, 41, 546, 123};
    InsertionSort(vec);
}

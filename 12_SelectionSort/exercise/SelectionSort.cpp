/*
Selection sort
1. cursor = 0
2. select the min element after cursor(index) then swap with cursor(index)
3. cursor++

Shell sort

index: 0  1  2  3  4
       |_____|
         gap
          |_____|
            gap
             |_____|
               gap

insert elements between gap
if j < gap then j - gap will not exist
vec[j-gap] > temp to find the insertion index

             j
index: 0  1  2  3  4
value: 5  4  3  2  1

while j >= gap(2) and vec[j-gap](5) > temp(3)

       j
index: 0  1  2  3  4
value: 5  4  5  2  1  (key = 3)

then insert key at j position

value: 3  4  5  2  1

now we increase i, j = i

then we get

!!! keep comparing when j>=gap
value: 1  2  3  4  5
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int MinIndex(vector<T> vec, int startindex) {
    int minindex = startindex;
    for(int i = startindex+1; i < vec.size(); i++) {
        if(vec[i] < vec[minindex]) {
            minindex = i;
        }
    }
    return minindex;
}

template<typename T>
void Display(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "  " ;
    }
    cout << "\n";
}

template<typename T>
void SelectionSort(vector<T>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        int minindex = MinIndex(vec, i);
        Swap(vec[i], vec[minindex]);
        Display(vec);
    }
}

template<typename T>
void ShellSort(vector<T>& vec) {
    // gap starts from half the size then decrease to 1
    for (int gap = vec.size() / 2; gap > 0; gap /= 2) { 
        // in every gap we do insertion sort (only seeing gaped elements)
        for(int i = gap; i < vec.size(); i++) { 
            // increase i to read all gaped elements
            T temp = vec[i];
            int j = i;
            while(j >= gap && vec[j-gap] > temp) { 
                // while there's still element at j-gap and this element is larger than temp
                vec[j] = vec[j-gap];
                j -= gap;
            }
            vec[j] = temp;
        }
        Display(vec);
    }
}

int main() {
    vector<int> vec1 = {123, 324, 43, 12, 3, 124, 456, 675, 246};
    vector<int> vec2 = {123, 324, 43, 12, 3, 124, 456, 675, 246};
    cout << "selection sort:\n";
    SelectionSort(vec1);
    cout << "shell sort:\n";
    ShellSort(vec2);
}

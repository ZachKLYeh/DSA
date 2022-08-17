/*
Quick sort is done by recurssive partitioning

Partition: select a pivot, then put the elements that less then the pivot left

partition is done by swapping sorted and unsorted arrays
i is the boundary of sorted array
j is the boundary of unsorted array

 p  i  j
{3, 4, 2, 5, 1}

if vec[j] < pivot swap vec[i], vec[j] then i++, j++

 p     i  j  
{3, 2, 4, 5, 1}

if vec[j] !< pivot, j++

 p     i     j  
{3, 2, 4, 5, 1}

if vec[j] < pivot swap vec[i], vec[j] then i++, j++

 p        i       
{3, 2, 1, 5, 4}

last, swap p with vec[i-1]

       p        
{1, 2, 3, 5, 4} 

now, 3 is the pivot of index 2


QuickSort is a combination of partition

pseudo code:
QuickSort(array, head, tail) {
    pivot_index = partition(array, head, tail)
    QuickSort(head, pivot_index-1);
    QuickSort(pivot_index+1);

}
pass1
 h                 t 
{3, 2, 6, 4, 5, 7, 1}

after partition
       p
{1, 2, 3, 6, 4, 5, 7}

divide into two 

{1, 2} {3} {6, 4, 5, 7}

partition
                  p
{1, 2} {3} {4, 5, 6, 7}
*/

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Print(vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << "  ";
    cout << "\n";
}

template<typename T>
// this function takes the first element as pivot 
// put elements smaller than pivot before pivor
// and larger elements after pivot
// then return pivot index
int Partition(vector<T>& vec, int head, int tail) {
    T pivot = vec[head];
    // i is the sorted index, j is the unsorted index
    int i = head + 1;
    for(int j = i + 1; j <= tail; j++) {
        if(vec[j] < pivot) {
            // if we found a element smaller then pivot
            // we swap it with the first unsorted element then increase sorted index
            Swap(vec[j], vec[i]);
            i++;
            //Print(vec);
        }
    }
    // last we place the pivot at the end of sorted index
    Swap(vec[i-1], vec[head]);
    // return pivot location
    return i-1;
}

template<typename T>
void _QuickSort(vector<T>& vec, int head, int tail) {
    if(head < tail) {
        int pivotindex = Partition(vec, head, tail);
        cout << "pivotindex:" << pivotindex << "\n";
        Print(vec);
        _QuickSort(vec, head, pivotindex-1);
        _QuickSort(vec, pivotindex+1, tail);
    }
}

template<typename T>
void QuickSort(vector<T>& vec) {
    _QuickSort(vec, 0, vec.size()-1);
}


int main(){
    vector<int> vec = {13, 26 ,4 ,1, 251, 4, 23, 2, 634, 2};
    QuickSort(vec);
    cout << "Sorted array:\n";
    Print(vec);
}



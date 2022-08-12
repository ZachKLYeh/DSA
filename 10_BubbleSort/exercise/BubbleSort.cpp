/*
Bubble sort is a sorting algorithm based on swapping
At each iteration, we run through the vector and check two elements value
Swap if the order is not correct.
In each iteration, we can make at least one element at the end of vector sorted
if there are n elements needs to be sorted
So the worst case we need to make n^2 calculation
Time complexity os O(n^2)

For space complexity is O(n), bubble sort doesn't use any extra space.

To avoid worst case, we added a bool swapped to see if there's swap operation within the iteration
If not, it indicates that the vector is sorted, then we can break the loop;
*/
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Display(vector<T> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "  " ;
    }
    cout << "\n";
}

template<typename T>
void BubbleSort(vector<T>& vec) {
    for (int i = 0; i < vec.size()-1; i++) {
        bool swapped = false;
        for (int j = 0; j < vec.size()-i-1; j++) {
            if (vec[j] > vec[j+1]) {
                Swap(vec[j], vec[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
        Display(vec);
    }
}

int main() {
    vector<int> vec = {13, 26, 3, 48, 239, 1982, 23, 54, 32, 54, 12398, 231, 435, 123, 654};
    Display(vec);
    BubbleSort(vec);
}

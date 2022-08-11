#include <iostream>
#include <vector>

using namespace std;

int linear_compair = 0;
int binary_compair = 0;

template<typename T, typename Function>
int LinearSearch(vector<T>& vec, T target, Function equal) {
    for (int i = 0; i < vec.size(); i++) {
        if (equal(vec[i], target)) return i;
    }
    return -1;
}

template<typename T>
bool Equal(T a, T b) {
    linear_compair++;
    return a==b;
    }

template<typename T, typename Function>
int BinarySearch(vector<T>& vec, T target, Function compare) {
    int head = 0;
    int tail = vec.size() - 1;
    while(head <= tail) {
        int mid = (head + tail) / 2;
        if (compare(vec[mid], target) == 0) return mid;
        if (compare(vec[mid], target) > 0) tail = mid - 1;
        if (compare(vec[mid], target) < 0) head = mid + 1;
    }
    return -1;
}

int Compare(int a, int b) {
    binary_compair++;
    return a - b;
}

int main() {
    vector<int> v{1, 3, 5, 7, 9, 13, 24, 45, 56};
    cout << "Original vectors: 1, 3, 5, 7, 9, 13, 24, 45, 56\n";
    cout << "Linear Seach number 9's index:";
    cout << LinearSearch(v, 9, Equal<int>) << "\n";
    cout << "Linear search compairsons:" << linear_compair << "\n";

    cout << "Binary Seach number 9's index:";
    cout << BinarySearch(v, 9, Compare) << "\n";
    cout << "Binary search compairsons:" << binary_compair << "\n";
}
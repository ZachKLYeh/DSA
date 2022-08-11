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

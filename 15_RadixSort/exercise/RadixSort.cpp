/*
Radix sort is a sorting algorithm based on count sort
Count sort is good for sorting numbers within a specific range

vec:   {2, 3, 2, 4, 1}
it iter through the vector then add to count index is a number appears
index:  0  1  2  3  4
count: {0, 1, 2, 1, 1}

then convert the count vector into accumulation form
count: {0, 1, 3, 4, 5}

now we can utilize the vector and count array to sort
output: {1, 2, 2, 3, 4}

Radix sort is accomplished by first finding the max number in vector
then decide the maximun exp

then doing count sort for several times
because count sort is very fast in small range of numbers
Radix sort is good within a smaller range of numbers
*/

#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void Print(vector<T> vec) {
    for(int i = 0; i < vec.size(); i++) cout << vec[i] << "  ";
    cout << "\n";
}

// get the max value within a vector
template<typename T>
T Max(vector<T> vec){
    T max = vec[0];
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > max) max = vec[i];
    }
    return max;
}

// do the count sort algorithm, which sorts fast with the range of 10
template<typename T>
void CountSort(vector<T>& vec, int exp) {
    vector<T> count(10, 0);
    vector<T> output(vec.size(), 0); 

    // using exp to cacluate the digits then put into count array
    for(int i = 0; i < vec.size(); i++) {
        count[(vec[i] / exp) % 10]++;
    }

    // transform count array into accumulation form
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // put vec into output according to count vector
    for(int i = vec.size() - 1; i >= 0; i--) {
        // using count to find the number of digit then -1 transform into index
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        // reduce one element on the digit
        count[(vec[i] / exp) % 10]--;
    }
    
    // put the counted array into vec
    for(int i = 0; i < vec.size(); i++) {
        vec[i] = output[i];
    }
}

template<typename T>
void RadixSort(vector<T>& vec) {
    T maximun = Max(vec);

    for(int exp = 1; maximun / exp > 0; exp *= 10) {
        CountSort(vec, exp);
        Print(vec);
    }
}

int main() {
    vector<int> vec = {132, 234, 13, 4, 1222, 541, 74, 36, 1, 623, 32664};
    RadixSort(vec);
}

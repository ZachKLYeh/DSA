/*
 Bucket Sort is a sorting algorithm based on interval
 It must work with another ordinary sorting algorithm
 In this implementation we use insertion sort

 1. get the max and min value of the vector
 2. calculate the bucket number and interval
    buckets = max - min + 1
    interval = (max - min) / (n_buckets - 1)
 3. put elements in original array into buckets according to its interval
 4. sort within each bucket
 5. concatenate buckets and generate the output
 */

#include<iostream>
#include<vector>

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
    }
}

template<typename T>
void BucketSort(vector<T>& vec) {
    // first find the min and max then decide number of buckets
    T min = vec[0];
    T max = vec[0];
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > max) max = vec[i];
        if(vec[i] < min) min = vec[i];
    }
    cout << "maxmun:" << max << "\n";
    cout << "minimun:" << min << "\n";

    // this is the formula of bucket numbers
    int n_buckets = max - min + 1;
    T interval = (max - min) / (n_buckets - 1);
    cout << "buckets:" << n_buckets << "\n";
    cout << "interval:" << interval << "\n";

    // create the empty buckets for storing vectors
    vector<vector<T>>buckets(n_buckets);
    for(int i = 0; i < vec.size(); i++) {
        buckets[(vec[i] - min) / interval].push_back(vec[i]);
    }
    
    // sort within each bucket then concatenate buckets
    int k = 0;
    for(int i = 0; i < n_buckets; i++) {
        if(buckets[i].size() > 0) {
            if(buckets[i].size() > 1) {
                InsertionSort(buckets[i]);
            }
            for(int j = 0; j < buckets[i].size(); j++) {
                vec[k] = buckets[i][j];
                k++;
            }
        }
    }
}

int main() {
    vector<float> vec = {0.132, 0.312, 0.003, 0.015, 0.523, 3.52, 4.12, 0.3, 3.2};
    Display(vec);
    BucketSort(vec);
    Display(vec);
}

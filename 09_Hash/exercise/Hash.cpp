#include <iostream>
#include "Hash.hpp"
using namespace std;

int main() {
    HashMap<int, int> hash;
    std::cout << "Insert 5 key/value pairs\n";
    hash.Insert(13, 130);
    hash.Insert(27, 270);
    hash.Insert(36, 360);
    hash.Insert(20, 200);
    hash.Insert(40, 400);
    hash.Display();
    std::cout << "Is the hashmap empty?" << hash.Empty() << "\n";
    std::cout << "Size of hashmap: " << hash.Size()<< "\n";
    std::cout << "Delete key 20\n";
    hash.Delete(20);
    hash.Display();
    std::cout << "Delete key 12\n";
    hash.Delete(12);
    hash.Display();
    std::cout << "Get value at key 40 is: " << hash.GetValue(40) << "\n";
    std::cout << "Get value at key 36 is: " << hash.GetValue(12) << "\n";
    std::cout << "Delete all elements\n";
    hash.Delete(40);
    hash.Delete(27);
    hash.Delete(13);
    hash.Delete(36); 
    std::cout << "Is the hashmap empty?" << hash.Empty() << "\n";
    std::cout << "Size of hashmap: " << hash.Size()<< "\n";
}

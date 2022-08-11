#include <iostream>
#include "Hash.hpp"
using namespace std;

int main() {
    HashMap<int, char> hash;
    char value = '0';
    std::cout << "Insert 5 key/value pairs\n";
    hash.Insert(13, 'A');
    hash.Insert(27, 'B');
    hash.Insert(36, 'C');
    hash.Insert(20, 'D');
    hash.Insert(40, 'E');
    hash.Display();
    std::cout << "Is the hashmap empty?" << hash.Empty() << "\n";
    std::cout << "Size of hashmap: " << hash.Size()<< "\n";
    std::cout << "Delete key 20\n";
    hash.Delete(20);
    hash.Display();
    std::cout << "Delete key 12\n";
    hash.Delete(12);
    hash.Display();
    hash.GetValue(40, value);
    std::cout << "Get value at key 40 is: " << value << "\n";
    hash.GetValue(36, value);
    std::cout << "Get value at key 36 is: " << value << "\n";
    std::cout << "Delete all elements\n";
    hash.Delete(40);
    hash.Delete(27);
    hash.Delete(13);
    hash.Delete(36); 
    std::cout << "Is the hashmap empty?" << hash.Empty() << "\n";
    std::cout << "Size of hashmap: " << hash.Size()<< "\n";
}

/*
Hashing is like a json file
{
    key   :   value
   "merry":   1999
   "james":   1966
   "tom"  :   2020
}

it is consists of key-and-value pairs.
how do we allocate the memory?
we allocate by using a hash function, which transfroms the key to hashmap index
each index contain a node pointer which points to a node

Hash Table index:   0   |  1  |  2  |
content:           node*|node*|node*|

node:
1. key
2. value


Insert:
Inserting in to a hashmap
1. create new node with key and value
2. calculate the map index of this node pointer
3. insert

Delete:
delete from a hashmap
1. use key to find the hashed index
2. check the node's key at the hahsed index
3. if is the same then relace the node with empty node
   else increase hashed index

*/
template<typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode(K key, V value): key(key), value(value) {}
};

template<typename K, typename V>
class HashMap {
public:
    HashNode<K, V>** map; // **  is a pointer to pointer
    HashNode<K, V>* empty;
    int capacity;
    int size;

    HashMap() {
        size = 0;
        capacity = 20;
        map = new HashNode<K, V>*[capacity]; // allocate mem for 20 hashnode pointers, map points to head 
        empty = new HashNode<K, V>(-1, -1); // a hash node of -1 key and -1 value is defined empty
        // init with NULL pointers
        for (int i = 0; i < capacity; i++) {
            map[i] = NULL;
        }
    } 
    
    int HashFunction(K key) {
    return key % capacity;
    }

    void Insert(K key, V value) {
        // create a new node, then assign it's pointer to temp
        HashNode<K, V>* temp = new HashNode<K, V>(key, value);
        // decide the index to save the node
        int hashindex = HashFunction(key);
        // or the hashindex position is occupied
        // increase the index (the policy of next space available)
        while (map[hashindex] != NULL && map[hashindex]->key != key && map[hashindex]->key != -1) {
            hashindex++;
            hashindex %= capacity;
        } 
        // if the hashindex position is not occupied, we can insert now
        map[hashindex] = temp;
        size++;
    }

    void Delete(K key) {
        int hashindex = HashFunction(key);
        
        while (map[hashindex] != NULL) {
            // if node in found
            if (map[hashindex]->key == key) {
                map[hashindex] = empty;
                size--;
                return;
            }
            else {
                hashindex++;
            }
        }
        std::cout << "The key is not found\n";
    }

    int GetValue(K key) {
        int hashindex = HashFunction(key);

        while (map[hashindex] != NULL) {
            // if node in found
            if (map[hashindex]->key == key) {
                return map[hashindex]->value;
            }
            else {
                hashindex++;
            } 
        }
        return -1;
    }

    bool Empty() {return size == 0;}

    int Size() {return size;}
    
    void Display() {
        for (int i = 0; i < capacity; i++) {
            if (map[i] != NULL && map[i]->key != -1) {
                std::cout << "index:" << i << "  ";
                std::cout << "key:" << map[i]->key << "  ";
                std::cout << "value:" << map[i]->value << "\n";
            }
        }
        std::cout << std::endl;
    }
};

/*
Queue is a LILO structure
the last element enter queue will be the last element that pop out
 
Queue require some methods inclue:
basic methods:
    push
    pop
    empty
    clear
advanced methods:
    set
    get

We're now implementing quere using linked list
The differece between array-based queue and list-based queue:

    Array-based queue provide faster access to elements in the middle of queue.
    Each operation takes O(1) at worst case.
    But suffer from memory reallocation when the array can not be expanded.

    List-based queue provide flexibility in changning queue size. 
    Without reallocating memory space.
    However, it suffered from accessing the elements in the middle of queue.
    Worst case could be O(n)
*/

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;

public:
    Queue();    // must include init method
    void Push(T element);
    T Pop();
    bool Empty();
    void Print();
};

template<typename T>
// :: here is used to access method in a object
// different from using . , :: is used to define method, . is used to reference methods
Queue<T>::Queue() { 
    //not using head = new Node(); tail = new Node(); 
    //because this create two new nodes on different memory address
    //now head and tail are pointers to the head node
    head = tail = new Node();
    head->next = 0;
}

template<typename T>
void Queue<T>::Push(T element) {
    Node* newnode = new Node();
    newnode->data = element;
    newnode->next = 0;
    tail->next = newnode;
    tail = newnode;
}

template<typename T>
T Queue<T>::Pop() {
    Node* p = head->next;
    if (p) {
        head->next = p->next;
        if (tail == p) tail = head;
        return p->data;
    }
    else {
        std::cout << "Empty queue cannot be popped\n";
        return p->data;
    }
}

template<typename T>
bool Queue<T>::Empty() {
    if (!head->next) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
void Queue<T>::Print() {
    Node* p = head->next;
    while(p) {
        std::cout << p->data << ", ";
        p = p->next;
    }
    std::cout << std::endl;
}
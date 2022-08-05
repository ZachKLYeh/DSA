/*
Linked list is constructed by nodes, each node point to the next node
The last node is point to zero
public methods:
get
set
insert
delete
push back(can it be replaced by insert?)
Print

head is an empty node
the first node is head->next
because push back function require extra work to  write into head node
*/

template<typename T>
class LinkedList{
private:
    // create a structure called node
    // each node contains data and a pointer to next node
    struct Node { 
        T data;
        Node* next; // next is a pointer to next node
    }; //struct ends with ;
    Node* head; // head is a pointer to first node

public:
    LinkedList() {
        // initial linked list by creating the head node
        head = new Node();
        head->next = 0; // -> is used to access variable in a struct
        // last node is point to zero, or false actually
    }

    T Get(int i) {
        Node* p = head->next;
        while (p && i) {
            p = p->next;
            i--;
        }
        if (!p) {
            std::cout << "Index out of range:" << std::endl;
            return p->data;
        }
        else{
            return p->data;
        }
    }

    void Set(int i, T element) {
        Node* p = head->next;
        while (p && i) {
            p = p->next;
            i--;
        }
        if (!p) {
            std::cout << "Index out of range, please provide valid index" << std::endl;
        }
        else{
            p->data = element;
        }
    }

    void Insert(int i, T element) {
        Node* p = head->next;
        Node* previous = p;
        while (p && i) {
            previous = p;
            p = p->next;
            i--;
        }
        if (!p) {
            std::cout << "Index out of range, please provide valid index" << std::endl;
        }
        else{
            Node* newnode = new Node();
            previous->next = newnode;
            newnode->next = p;
            newnode->data = element;
        }

    }

    void Delete(int i) {
        Node* p = head->next;
        Node* previous = p;
        while (p && i) {
            previous = p;
            p = p->next;
            i--;
        }
        if (!p) {
            std::cout << "Index out of range, please provide valid index" << std::endl;
        }
        else{
            previous->next = p->next;
        }


    }

    void PushBack(T element) {
        Node* p = head; //p is a pointer to head
        // read all elements in the linked list until it points to none
        while (p->next) {
            p = p->next;
        }
        //now p is the pointer to the last node
        //create a new node next to last node
        p->next = new Node();
        if (!p->next) {
            std::cout << "Failed to push a new node, please check memory space" << std::endl;
        }
        else {
            p->next->next = 0;
            p->next->data = element;
        }
    }

    void Print() {
        Node* p = head;
        while (p->next) {
            p = p->next;
            std::cout << p->data << "  ";
        }
        std::cout << std::endl;
    }

    void Reverse() {
        Node* currentnode = head->next;
        Node* previousnode = 0;
        while(currentnode) {
            Node* nextnode = currentnode->next; // save the next node
            currentnode->next = previousnode; // point current node to previous node
            previousnode = currentnode; //assign previous node with current node
            currentnode = nextnode; //assign current node with next node
            }
        head = new Node(); //create a new head point to the first index of linked list
        head->next = previousnode;
    }
};
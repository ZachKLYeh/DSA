/*
stack is a FIFO structure

methods:
push
pop
check empty
clear
elements

reallocate
*/

template<typename T>
class Stack {
private:
    int capacity = 3;
    int elements = 0;
    T* top; // pointer to the top of stack
    T* buttom; // pointer to the buttom of stack

public:
    Stack() {
        buttom = new T[capacity];
        if (!buttom) {
            std::cout << "Failed to build stack\n";
        }
        else {
            top = buttom-1;
        }
    }

    void Push(T element) {
        if (elements+1 >= capacity) {
            Reallocate();
        }
        top++;
        elements++;
        *top = element;
    }

    T Pop() {
        top--;
        elements--;
        return *top;
    }

    void Empty() {
        if (elements == 0) {
            std::cout << "True" << std::endl;
        }
        else {
            std::cout << "False" << std::endl;
        }
    }

    void Clear() {
        top = buttom-1;
        elements = 0;
    }

    void Reallocate() {
        capacity = capacity *2;
        T* new_buttom = new T[capacity];
        T* new_top;
        new_top = new_buttom + (top - buttom);
        for (int i = 0; i < elements; i++) {
            *(new_buttom+i) = *(buttom+i);
        }
        top = new_top;
        buttom = new_buttom;
    }

    void Print() {
        for (int i = 0; i < elements; i++) {
            std::cout << *(buttom+i) << "  ";
        }
        std::cout << std::endl;
    }

};
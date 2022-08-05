/*array list include several methods

public methods:
    get
    set
    push_back
    pop_back
    insert
    delete
    find

private methods:
    relloc
*/

//first create template for datatype supppport

template<typename T>
class ArrayList {
    //first stage create self variables
    T* head; //pointer to type T
    int n_elements = 0;
    int capacity = 1;

//then build the public methods
public:
    //init method
    ArrayList() {
        //data is a pointer to the starting point of arraylist
        head = new T[capacity]; //new will create several type T data then assign the pointer to data
        if (!head) {
            std::cout << "Failed to allocate " << capacity << " elements";
        }
    }

    void push_back(T element) {
        if (n_elements+1 > capacity) {
            reallocate();
        }
        head[n_elements] = element;
        n_elements++;
    }

    void pop_back() {
        n_elements--;
    }

    int get_size() {
        return n_elements;
    }

    T get_element(int i) {
        return head[i];
    }

    void set_element(int i, T element) {
        head[i] = element;
    }

    void insert_element(int i , T element) {
        if (n_elements > capacity) {
            reallocate();
        }
        for (int j = n_elements; j >= i; j--) {
            head[j+1] = head[j];
        }
        head[i] = element;
        n_elements++;
    }

    //delete elemet by index
    void delete_element(int i) {
        for (i; i < n_elements; i++) {
            head[i] = head[i+1];
        }
        n_elements--;
    }

    void find_index(T element) {
        for (int i = 0; i < n_elements; i++) {
            if (head[i] == element) {
                std::cout << i << "\n";
            }
        }
    }

    void print_list() {
        T e;
        for (int i = 0; i < n_elements; i++) {
            e = get_element(i);
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }

    void reallocate() {
        capacity = capacity*2;
        T* new_head;
        new_head = new T[capacity];
        for (int i = 0; i < n_elements; i++) {
            new_head[i] = head[i];
        }
        head = new_head;
    }

};

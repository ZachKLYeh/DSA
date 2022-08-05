template<typename T> //variable type name is T, variable type is not fixed
class SqlList {
	T* data;  //data is a pointer to one element in SqlList
	int capacity, n; //declare private variables

public:
	SqlList(int cap = 3) { //init method
		data = new T[cap]; //allocate three elements 
		if(!data) throw "SqlList allocationi failed"; //see if allocation suceeded
		capacity = cap; n = 0; //init with 0 elements, 3 element capacity
	}
	bool get(int i, T &e) { //& here is not address, is reference of the original data
		if (i < 1 || i > n) 
			return false;
		e = data[i - 1]; 
		return true;
    }
	bool set(int i, T e) { //modify ith element to value e
		if (i < 1 || i > n) 
			return false;
		data[i - 1] = e; 
		return true;
	}
	bool push_back(T e) { //push an element to the back of list
		if (n==capacity) {
			if (!realloc()) {
				return false;
			}
		 }
		data[n] = e;
		n++;
		return true;
	}
	int size() { //return the size of the list
		return n;
	}
	bool insert(int i, T e) { //insert e at ith position
		if (i < 1 || i > n + 1) return false;
		if (n == capacity) 
			if (!realloc()) return false;
			
		for (int j = n; j >= i; j--) {
			data[j] = data[j - 1];
		}
		data[i - 1] = e;
		n++;
		return true;
	}
	bool remove(int i) { //remove ith element
		if (i < 1 || i > n) return false;
		
		for (int j = i+1; j <= n; j++) {
			data[j - 2] = data[j - 1];
		}
		n--;
		return true;
	}
	bool pop_back() { //remove last element in the list
		if (n == 0) return false;
		n--;
		return true;
	}
	bool remove_front() { //remove first element in the list
		for (int j = 2; j <= n; j++) {
			data[j - 2] = data[j - 1];
		}
		n--;
		return true;
	}
	int find(int pos,T e) { //find position of an element
		for (int i = pos; i <= n; i++)
			if (data[i-1] == e) {
				return i;
			}
		return 0;
	}
private: //if the list exceed original size, double the capacity
	bool realloc() {
		T* p = new T[2 * capacity];
		if (!p) return false;
		for (int i = 0; i < n; i++) 
			p[i] = data[i];
		delete[] data;
		data = p;
		capacity *= 2;
		return true;
	}
	
};

template<typename T>
void print(SqlList<T>& L) { //print all elements in a arraylist
	T e; 
	for (int i = 1; i <= L.size(); i++) {
		L.get(i, e);
		std::cout << e << " ";
	}
	std::cout << std::endl;

}
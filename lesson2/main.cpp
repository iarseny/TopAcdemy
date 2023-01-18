#include <iostream>

class Array {
    int *arr;
    int size;
    int cap;

    public:
    explicit Array(int cap) {
        this->arr = new int[cap];
        this->cap = cap;
        size = 0;
    }

    void add_back(int val) {
        if (size + 1 <= cap) {
            this->arr[size] = val;
            size++;
        } else {
            std::cout << "no cap" << std::endl;
        }
    }

    void print() const{
        for (int i = 0; i < size; i++) {
            std::cout << this->arr[i] << " ";
        }
    }

    ~Array() {
        std::cout << std::endl << "Объект удалён" << std::endl;
    }

};


int main() {
    Array array(15);

    array.add_back(1);
    array.add_back(2);
    array.add_back(3);
    array.add_back(4);
    array.add_back(5);

    array.print();
}
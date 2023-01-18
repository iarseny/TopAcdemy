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

    void insert(int index,int cherepaxa) {
        if (index + 1 <= this-> size) {
            this->arr[index] = cherepaxa;
        } else {
            std::cout << "много";
        }
    }

    void delete_index(int index) {
        if (index + 1 < this->size) {
            int *tmp = this->arr;
            this->arr = new int[size - 1];
            delete [] this->arr;
            size--;
            for (int i = 0; i < index + 1; i++) {
                this->arr[i] = tmp[i];
            }

            for (int j = index + 1; j < size + 1; j++) {
                this->arr[j - 1] = tmp[j];
            }

            delete [] tmp;
        } else {
            std::cout << "черепаха, много";
        }
    }

    ~Array() {
        delete [] this->arr;
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
    array.insert(1,8);

    std::cout << std::endl << std::endl;

    array.print();

    std::cout << std::endl << std::endl;

    array.delete_index(0);

    array.print();
}
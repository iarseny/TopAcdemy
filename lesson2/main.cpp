#include <iostream>

class Array {
    int *arr;
    int size;
    int cap;

    public:
    int w = 7;
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
        int *tmp = this->arr;
        this->arr = new int[size - 1];
        size--;
        for (int i = 0; i < index + 1; i++) {
            this->arr[i] = tmp[i];
        }

        for (int j = index + 1; j < size + 1; j++) {
            this->arr[j - 1] = tmp[j];
        }

        delete [] tmp;
    }

    Array &operator-(const Array &array) {

        if (this->size > array.size) {
            for (int i = 0; i < this->size; i++) {
                this->arr[i] = this->arr[i] - array.arr[i];
            }
        } else if (this->size == array.size) {
            for (int i = 0; i < this->size; i++) {
                this->arr[i] = this->arr[i] - array.arr[i];
            }
        } else {
            for (int i = 0; i < array.size; i++) {
                array.arr[i] = array.arr[i] - this->arr[i];
            }
        }

        return *this;
    }

    ~Array() {
        delete [] this->arr;
    }

    bool operator>(int znach) {

        return this->size > znach;
    }

    bool operator<(int znach) {

        return this->size < znach;
    }

    bool operator<=(int znach) {

        return this->size <= znach;
    }

    bool operator>=(int znach) {

        return this->size >= znach;
    }

    bool operator==(int znach) {

        return this->size == znach;
    }

};


int main() {
    Array array(15);
    Array array2(15);


    array.add_back(2);
    array.add_back(2);
    array.add_back(3);
    array.add_back(4);
    array.add_back(5);

    array2.add_back(1);
    array2.add_back(2);
    array2.add_back(3);
    array2.add_back(4);
    array2.add_back(5);

    //array - 1 - 2

    array - array2;

    array.print();
}
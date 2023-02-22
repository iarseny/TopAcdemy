#include <iostream>
#include <memory>


template <typename T>
class Array {
    std::unique_ptr<T []> *array;
    int size;
    int cap;

    public:

    Array(const Array &other) {}
    Array(int size) {
        //delete this->array;
        this->array = new std::unique_ptr<T []>(new T[this->size]);
        this->size = size;
    }


    void add_begin(T val) {
        this->size++;
        std::unique_ptr<T []> *new_array = new std::unique_ptr<T []>(new T[this->size]);
        new_array->get()[0] = val;
        for (int i = 0; i < this->size - 1; i++) {
            new_array->get()[i + 1] = (this->array)->get()[i];
        }

        this->array = new_array;

    }
    void add_end(T val) {
        this->size++;
        std::unique_ptr<T []> *new_array = new std::unique_ptr<T []>(new T[this->size]);
        for (int i = 0; i < this->size - 1; i++) {
            new_array->get()[i] = (this->array)->get()[i];
        }

        new_array->get()[this->size - 1] = val;

        this->array = new_array;
    } // добавить в конец

    void del_begin() {
        this->size--;
        std::unique_ptr<T []> *new_array = new std::unique_ptr<T []>(new T[this->size]);

        for (int i = 1; i < this->size; i++) {
            new_array->get()[i - 1] = (this->array)->get()[i];
        }

        this->array = new_array;
    } // удалить из начала
    void del_end() {} // удалить из конца

    void print() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->array->get()[i] << " ";
        }
    } // вывести массив

    ~Array() {}
};


int main() {

    Array<int> array(5);

    array.add_begin(6);

    array.del_begin();

    array.print();

    return 0;
}
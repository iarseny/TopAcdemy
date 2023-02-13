#include <iostream>
#include "class2.cpp"
#include "class3.cpp"

namespace class_array {
    template<typename T>
    class Array {
        int size = 0;
        T *array;

        public:
        Array() {
            this->array = new T[this->size];
        }

        void add_begin(T val) {
            T *tmp = this->array;
            this->size++;
            this->array = new T[this->size];
            this->array[0] = val;
            for (int i = 1; i < this->size; i++) {
                this->array[i] = tmp[i - 1];
            }

            delete [] tmp;

        }

        void add_end(T val) {
            T *tmp = this->array;
            this->size++;
            this->array = new T[this->size];
            for (int i = 0; i < this->size - 1; i++) {
                this->array[i] = tmp[i];
            }
            this->array[this->size - 1] = val;
        }

        void delete_beginning() {
            this->size--;
            T *tmp = this->array;
            this->array = new T[this->size];
            for (int i = 1; i < this->size + 1; i++) {
                this->array[i - 1] = tmp[i];
            }

            delete [] tmp;
        }

        int operator[](int index) {
            return this->array[index];
        }

        int get_size() {
            return this->size;
        }

        void delete_end() {
            this->size--;
            T *tmp = this->array;
            this->array = new T[this->size];
            for (int i = 0; i < this->size; i++) {
                this->array[i] = tmp[i];
            }
            delete [] tmp;
        }

        void set_index(int index, int val) {
            this->array[index] = val;
        }

        std::string get_type() {
            return "array";
        }

    };
}

int main() {

    list_class::List<int> list;

    class_algoritm::Algoritm<list_class::List<int>> algoritm;

    list.add_to_begin(5);
    list.add_to_begin(6);
    list.add_to_begin(7);

    algoritm.print(list);

    return 0;
}
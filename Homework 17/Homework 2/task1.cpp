#include <iostream>

template<typename T>
class Task {
    T *arr;
    int size;

    public:
    Task() {}

    void create(int size) {
        this->arr = new T[size];
        this->size = size;

        std::cout << "Введите масив: \n";

        for (int i = 0; i < this->size; i++) {
            std::cin >> this->arr[i];
        }
    }

    void del() {
        delete [] this->arr;
    }

    void print() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->arr[i] << std::endl;
        }
    }

    void add(T val) {
        this->size++;
        T *tmp = this->arr;
        this->arr = new T[this->size];

        for (int i = 0; i < this->size - 1; i++) {
            this->arr[i] = tmp[i];
        }

        this->arr[this->size - 1] = val;
    }

    void add(T val, int index) {
        if (index <= this->size - 1) {
            this->size++;
            T *tmp = this->arr;
            this->arr = new T[this->size];
            for (int i = 0; i < index; i++) {
                this->arr[i] = tmp[i];
            }
            this->arr[index] = val;

            for (int i = index; i < this->size - 1; i++) {
                this->arr[i + 1] = tmp[i];
            }

            delete [] tmp;
        } else {
            int tmp_size = this->size;
            this->size += (index + 1) - this->size;
            T *tmp = this->arr;
            this->arr = new T[this->size];

            for (int i = 0; i < tmp_size; i++) {
                this->arr[i] = tmp[i];
            }

            for (int i = tmp_size; i < this->size; i++) {
                this->arr[i] = val;
            }
            delete [] tmp;
        }
    }

    void del(int index) {
        if (index <= this->size - 1) {
            this->size--;
            T *tmp = this->arr;

            this->arr = new T[this->size];
            for (int i = 0; i < index; i++) {
                this->arr[i] = tmp[i];
            }

            for (int j = index; j < this->size; j++) {
                this->arr[j] = tmp[j + 1];
            }

            delete [] tmp;
        }
    }

};



int main() {

    Task<int> task;

    task.create(3);

    std::cout << std::endl;

    task.add(6, 2);

    task.del(2);

    task.print();

    return 0;
}
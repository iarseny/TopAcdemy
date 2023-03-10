#include <iostream>

class Task {
    int *array1;
    int *array2;
    int size1, size2;

    public:
    Task() {
        std::cout << "Введите 1 и 2 размер: \n";
        std::cin >> this->size1 >> this->size2;

        std::cout << "Ведите 1 массив:\n";

        this->array1 = new int[this->size1];
        for (int i = 0; i < this->size1; i++) {
            std::cin >> this->array1[i];
        }

        std::cout << "Ведите 2 массив:\n";

        this->array2 = new int[this->size2];
        for (int i = 0; i < this->size2; i++) {
            std::cin >> this->array2[i];
        }

    }

    int get_size() {
        int size = 0;
        for (int i = 0; i < this->size1; i++) {
            bool in_array = false;
            for (int j = 0; j < this->size2; j++) {
                if (this->array1[i] == this->array2[j]) {
                    in_array = true;
                }
            }
            if (!in_array) {
                size++;
            }
        }

        return size;
    }

    void fill(int *array) {
        int iter = 0;
        for (int i = 0; i < this->size1; i++) {
            bool in_array = false;
            for (int j = 0; j < this->size2; j++) {
                if (this->array1[i] == this->array2[j]) {
                    in_array = true;
                }
            }
            
            if (!in_array) {
                array[iter] = this->array1[i];
                iter++;
            }
        }
    }

    void print(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << "\n";
        }
    }

    ~Task() {
        delete [] this->array1;
        delete [] this->array2;
    }

};

int main() {

    Task task;

    int new_size = task.get_size();

    int *new_array = new int[new_size];

    task.fill(new_array);

    std::cout << std::endl;

    task.print(new_array, new_size);

    delete [] new_array;

    return 0;
}
#include <iostream>

class Task {
    int *array1;
    int array2;
    int size1, size2;

    public:
    Task() {
        std::cout << "Введите 1 и 2 размер: \n";
        std::cin >> this->size1 << this->size2;

        this->array1 = new int[this->size1];
        for (int i = 0; i < this->size1; i++) {
            std::cin >> this->array1[i];
        }

        this->array2 = new int[this->size2];
        for (int i = 0; i < this->size2; i++) {
            std::cin >> this->array2[i];
        }

    }

};
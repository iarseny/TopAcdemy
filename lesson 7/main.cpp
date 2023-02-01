#include <vector>
#include <iostream>


template<typename T>
class Array {
    int size;
    T *array;

    public:
    Array(int size,T val) {

    }
};

int main() {

    int pointer_array[5] = {1,2,3,4,5};

    std::vector<int> array(&(pointer_array[0]),&(pointer_array[8]));

    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i] << "  ";
    }

    std::vector<int>::iterator i;

    return 0;
}
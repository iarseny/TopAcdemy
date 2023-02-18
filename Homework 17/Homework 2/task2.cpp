#include <iostream>


int *f(int *arr, int size) {
    int p_chisel = 0;
    for (int i = 0; i < size; i++) {
        int delitel = 0;

        for (int j = 1; j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                delitel++;
            }
        }

        
        if (delitel == 2) {
            p_chisel++;
        }
    
    }


    int *res = new int[p_chisel];

    int index = 0;

    for (int i = 0; i < size; i++) {
        int delitel = 0;

        for (int j = 1; j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                delitel++;
            }
        }

        
        if (delitel != 2) {
            res[index] = arr[i];
            index++;
        }
    
    }

    std::cout << std::endl;

    for (int i = 0; i < size - p_chisel; i++) {

        std::cout << res[i] << " ";
    }

    return res;

}


int main() {

    int array[5] = {1,2,3,4,5};

    int size = sizeof(array) / sizeof(int);

    int *new_array = f(array, size);

    delete [] new_array;

    return 0;
}
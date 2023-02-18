#include <iostream>

void f(int *arr, int size) {
    int pol;
    int otr;
    int zero;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            pol++;
        } else if(arr < 0) {
            otr++;
        } else {
            zero++;
        }
    }

    int *first = new int[pol];
    int *second = new int[otr];
    int *third = new int[zero];

    int i1 = 0, i2 = 0, i3 = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            first[i1] = arr[i];
            i1++;
        } else if(arr < 0) {
            second[i2] = arr[i];
            i2++;
        } else {
            third[i3] = arr[i];
            i3++;
        }
    }

    std::cout << "Done !";
}

int main() {

    int array[5] = {1,2,3,4,5};

    int size = sizeof(array) / sizeof(int);

    f(array, size);

    return 0;
}
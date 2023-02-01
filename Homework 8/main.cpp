
#include <stdlib.h>
// Нам понадобится функция qsort
#include <iostream>

//Для qsort
int bigger (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

class Array {
    int *array;
    int size;
    public:
    Array(int *arr,int size) {
        this->array = arr;
        this->size = size;
    }

    void show() {
        for (int i = 0; i < this->size; i++) {
            std::cout << this->array[i] << "  ";
        }
    }

    int min() {
        int res = this->array[0];
        for (int i = 1; i < this->size; i++) {
            if (this->array[i] < res) {
                res = this->array[i];
            }
        }

        return res;
    }

    int max() {
        int res = this->array[0];
        for (int i = 1; i < this->size; i++) {
            if (this->array[i] > res) {
                res = this->array[i];
            }
        }

        return res;
    }

    void sort() {
        qsort(this->array,8,sizeof(int),bigger);
    }

    int search(int k) {
        bool flag = false;
        int l = 0; // левая граница
        int r = this->size - 1; // правая граница
        int mid;
        int key = k;
 
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]
    
            if (this->array[mid] == key) flag = true; //проверяем ключ со серединным элементом
            if (this->array[mid] > key) r = mid - 1; // проверяем, какую часть нужно отбросить
            else l = mid + 1;
        }

        return mid;
    }

    void change(int index,int val) {
        this->array[index] = val;
    }
};

int main() {

    int array[] = {1,2,4,5};

    Array arr(array,4);

    //arr.sort();

    arr.show();

    return 0;
}
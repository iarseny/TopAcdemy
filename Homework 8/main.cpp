#include <iostream>
#include <algorithm>
#include <vector>

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

    void sorting() {
        std::vector<int> vec(&(this->array[0]),&(this->array[this->size]));

        sort(vec.begin(), vec.end());

        for (int i = 0; i < this->size; i++) {
            this->array[i] = vec[i];
        }

    }

    int search(int k) {
        bool flag = false;
        int l = 0;
        int r = this->size - 1;
        int mid;
        int key = k;
 
        while ((l <= r) && (flag != true)) {
            mid = (l + r) / 2;
    
            if (this->array[mid] == key) flag = true;
            if (this->array[mid] > key) r = mid - 1;
            else l = mid + 1;
        }

        return mid;
    }

    void change(int index,int val) {
        this->array[index] = val;
    }
};

int main() {

    int array[] = {2,1,4,5};

    Array arr(array,4);

    arr.sorting();

    arr.show();

    return 0;
}
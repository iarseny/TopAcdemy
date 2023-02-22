#include <iostream>
#include <map>
#include <memory>



template <typename T>
class my_ptr {
    static std::map<T *, int> ptrs;
    T *ptr;


    public:
        my_ptr() : my_ptr(NULL) {}

        my_ptr(const my_ptr &other) {
            this->ptrs[other.ptr]++;
            this->ptr = other.ptr;
        }
        // my_ptr(const my_ptr &other) = delete; // for unique

        my_ptr(T *ptr) {
            this->ptrs[ptr] = 1;
            this->ptr = ptr;
        }

        ~my_ptr() {
            // delete this->ptr;
            this->ptrs[this->ptr]--;
            if (this->ptrs[this->ptr] == 0) {
                delete this->ptr;
            }
        }
};

template <typename T>
std::map<T *, int> my_ptr<T>::ptrs;

int foo() {
    // int *ptr = new int();
    // int a = 5;
    // std::unique_ptr<int> u_ptr(new int());
    // std::unique_ptr<int> u_ptr2(u_ptr);

    // std::shared_ptr<int> sh_ptr(new int());
    // std::shared_ptr<int> sh_ptr2(sh_ptr);

    my_ptr<int> ptr(new int());
    my_ptr<int> ptr2(ptr);

    std::cout << "Hello\n";
    return 1;
}

int main() {
    try {
        foo();
    } catch (const char *err) {

    }
    // delete [] ptr;
}
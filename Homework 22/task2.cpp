#include <iostream>
#include <map>

template<typename T>
class unique_ptr {
    T *t;
    public:
    unique_ptr(const unique_ptr &u) = delete;
    unique_ptr(T *q) {
        this->t = q;
    }

    T get() {
        return *(this->t);
    }

    ~unique_ptr() {
        delete this->t;
    }
};

template<typename T>
class shared_ptr {
    static std::map<T *, int> ptrs;
    T *ptr;


    public:
        shared_ptr() : shared_ptr(NULL) {}

        shared_ptr(const shared_ptr &other) {
            this->ptrs[other.ptr]++;
            this->ptr = other.ptr;
        }

        shared_ptr(T *ptr) {
            this->ptrs[ptr] = 1;
            this->ptr = ptr;
        }

        ~shared_ptr() {
            this->ptrs[this->ptr]--;
            if (this->ptrs[this->ptr] == 0) {
                delete this->ptr;
            }
        }
};

template <typename T>
std::map<T *, int> shared_ptr<T>::ptrs;

int main() {
    unique_ptr<int> uniq(new int(5));
    std::cout << uniq.get();

    shared_ptr<int> uniq2(new int(3));
    shared_ptr<int> uniq3(uniq3);
    return 0;
}
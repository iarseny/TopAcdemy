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
class sharped_ptr {
    T *t;
    static std::map<T *, int> m;

    public:
    shared_ptr(const shared_ptr &sh) {}
};


int main() {
    unique_ptr<int> uniq(new int(5));
    std::cout << uniq.get();
    return 0;
}
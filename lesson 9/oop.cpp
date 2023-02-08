#include <iostream>

class D {
    int h = 5;
    public:
    int g = 8;

    void r() {
        std::cout << 78;
    }
};

class A : private D {
    public:
    void print() {
        this->r();
    }
};

int main() {

    A a;

    a.print();

    return 0;
}
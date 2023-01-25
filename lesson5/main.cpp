#include <iostream>


class Point {

    int *count;

    public:

    
    Point() : Point(5) {}

    Point(int t) {
        this->count = new int(t);
    }

    Point &operator+(const Point &other) {
        *(this->count) = *(other.count);
        return *this;
    }

    void get() {
        std::cout << *(this->count);
    }

    int get_X() {
        return *(this->count);
    }

    ~Point() {
        delete this->count;
    }

};

template<typename T>
std::ostream &operator>>(std::ostream &stream, T &point) {
    stream << point.get_X();
    return stream;
}

int main() {

    Point one;

    Point two(6);

    one + two;

    /*

    for (int i =0; i < this->size)

    */

    std::cout >> two;

    return 0;
}
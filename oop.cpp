#include <iostream>

class Point {
    private:
    int x,y;

    public:
    Point() : Point(5,5) {}

    Point(int x,int y) {
        this->x = x;
        this->y = y;
    }

    void print() {
        std::cout << x << "  " << y;
    }

    void setX(const int &t) {
        this->x = t;
    }
};


int main() {

    Point point (7,7);

    point.print();

    point.setX(8);

    point.print();

    return 0;
}


#include <iostream>
#include "task3.cpp"

class Circle {
 private:
    q::Point d;

    int r;

 public:

    Circle() : Circle(q::Point(5,5),5) {}

    Circle(q::Point d, int r) {
        this->d = d;
        this->r = r;
    }

    q::Point getD() const {
        return this->d;
    }
    int getR() const {
        return this->r;
    }

    void setD(q::Point other) {
        this->d = other;
    }

    void setR(int other) {
        this->r = other;
    }

};

std::ostream &operator<<(std::ostream &out, const Circle& c) {
    out << c.getD().getX() << "  " << c.getD().getY() << ", " << c.getR();
    return out;
}


int main()
{
    Circle circles[3] {Circle(q::Point(1,2),2), Circle(), Circle(q::Point(1,2), 56)};
   
    for (int i = 0; i < 3; i++) {
        std::cout <<  circles[i];
    }
}
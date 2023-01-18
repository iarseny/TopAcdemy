#include <iostream>
#include <string>

struct Data {

};

class Point {
    private:

    int x,y;

    public:
    Point() : Point(5,5) {
        static int prevID = 0;
    }

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

class User {
    private:
        std::string name;
        int sum;
        int year,month,year;
        int id;
        Data data;

    public:
        User() {}
        User(const User &other) {}
        User(std::string name,Data new_data) {

        }
    
};


int main() {

    Point point (7,7);

    point.print();

    point.setX(8);

    point.print();

    return 0;
}


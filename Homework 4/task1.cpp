#include <iostream>

class Overcoat {
    int price;
    std::string model;

public:
    Overcoat() : Overcoat(5000,"coat") {}

    Overcoat(int price,std::string model) {
        this->price = price;
        this->model = model;
    }

    bool operator==(Overcoat things) {
        if (this->model == things.model) {
            return true;
        } else {
            return false;
        }
    }

    bool operator>(Overcoat things) {
        if (this->model != things.model && this->price > things.price) {
            return true;
        } else {
            return false;
        }
    }

    void operator=(Overcoat things) {
        this->price = things.price;
        this->model = things.model;
    }

};

int main() {

    Overcoat one;
    Overcoat two(9000,"bag");

    std::cout << (one == two) << std::endl;

    std::cout << (two > one) << std::endl;

    one = two;

    return 0;
}
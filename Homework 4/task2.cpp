#include <iostream>

class Flat {

    int price;
    int S;

    public:
    Flat() : Flat(6000000,40) {}

    Flat(int price,int S) {
        this->price = price;
        this->S = S;
    }

    bool operator==(Flat flat) {
        if (this->S == flat.S) {
            return true;
        } else {
            return false;
        }
    }

    void operator=(Flat flat) {
        this->price = flat.price;
        this->S = flat.S;
    }

    bool operator>(Flat flat) {
        if(this->price > flat.price) {
            return true;
        } else {
            return false;
        }
    }

};


int main() {

    Flat one;

    Flat two(9000000,40);

    std::cout << (one == two) << std::endl;

    std::cout << (one > two);

    one = two;

    return 0;
}
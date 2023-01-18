#include <iostream>

class OOP {

    public:
    OOP() {
        static int thing = 0;
        thing++;
        std::cout << thing << " ";
    }

};

int main() {

    OOP oop;
    OOP rrr;
}
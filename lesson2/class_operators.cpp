#include <iostream>

class Go {
    public:
    Go() {
        std::cout << 6 + 7.6 << std::endl;
    }
    private:
    int integer = 6;
    public:
    static const int gear = 6;
    template<typename T>
    T operator*(T znach) {
        return this->integer + znach;
    }

    bool operator>(int something) {
        if (this->integer > something) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Go go;

    std:: cout << go * 8.8  << std::endl;

    std::cout << Go::gear;

    return 0;
}
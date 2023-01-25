#include <iostream>

template<typename T>
class Temp {
    T h = 5;

    public:

    T function() {
        return h + 8;
    }
};



int main() {

    Temp<int> go;

    std::cout << go.function();

    return 0;
}
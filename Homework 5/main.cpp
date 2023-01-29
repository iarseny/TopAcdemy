#include <iostream>

class Book {
    public:
    std::string *name;

    public:
    Book() {
        this->name = new std::string("Undefined");
    }

    ~Book() {
        delete this->name;
    }
};

int main() {
    Book book;


    return 0;
};
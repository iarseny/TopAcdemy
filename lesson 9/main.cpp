#include <iostream>


class Parent {
    protected:
    int something = 8;
    std::string name;
    public:
    Parent() : Parent("Parent") {}

    Parent (std::string name) {

    }

    void hello() {
        std::cout << "Hello" << std::endl;
    }

    void one() {
        std::cout << 5;
    }

    virtual ~Parent() {
        std::cout << std::endl << 777 << std::endl;
    }
};

class Child : public Parent {
    public:

    Child() : Parent() {}
        void sayHIbyName(const std::string &name) {
            std::cout << this->something << std::endl;
        }

        void f();

        static void help() {
            std::cout << std::endl << "Как дела ?" << std::endl;
        }

        void one() {
            std::cout << std::endl << 6;
        }

        ~Child() {
            std::cout << std::endl << 555 << std::endl;
        }
};


void Child::f() {
    std::cout << "goodbye !";
}


int main() {

    Child child;

    child.sayHIbyName("qqq");

    child.hello();

    Child::help();

    child.f();

    child.one();

    return 0;
}
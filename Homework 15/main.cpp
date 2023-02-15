#include <iostream>

class Pet {
    public:

    template<typename T, typename B, typename A>
    Pet(T &q, std::string name1, B &r, std::string name2, A &g, std::string name3) {
        q.name = name1;
        r.name = name2;
        g.name = name3;
    }
};

class Parrot {
    std::string name;
    friend class Pet;
    public: void print(){std::cout << this->name << std::endl;}
};

class Dog {
    std::string name;
    friend class Pet;
    public: void print(){std::cout << this->name << std::endl;}
};

class Cat {
    std::string name;
    friend class Pet;
    public: void print(){std::cout << this->name << std::endl;}
};


int main() {

    Parrot p;
    
    Dog d;

    Cat c;

    Pet pet(p,"parrot", d ,"dog", c,"cat");

    p.print();

    return 0;
}
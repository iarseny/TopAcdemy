#include <iostream>

class Dvigatel {
    int mochnost;
    int ves;
    std::string name;

    public:
    Dvigatel() {}

    Dvigatel(int v, int m, std::string n) {
        this->ves = v;
        this->name = n;
        this->mochnost = m;
    }
    
    int get_ves() {
        return this->ves;
    }

    int get_mochnost() {
        return this->mochnost;
    }

    std::string get_name() {
        return this->name;
    }

};

class Car {
    int d;
    int p;
    std::string color;

    public:
    Car() {}

    Car(int d,int p,std::string c) {
        this->d = d;
        this->p = p;
        this->color = c;
    }

    int get_price() {
        return this->p;
    }

};

std::ostream &operator<<(std::ostream &out, Dvigatel dvigatel) {

    out << dvigatel.get_name() << "\n";

    out << dvigatel.get_ves() << "\n";

    out << dvigatel.get_mochnost();

    return out;
}

std::ostream &operator<<(std::ostream &out,Car car) {
    return out << std::endl << car.get_price();
}


int main() {

    Dvigatel d(5000,3000,"Mersedes");

    Car car(4,8,"blue");

    std::cout << d << car;

    return 0;
}
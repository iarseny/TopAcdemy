#include <iostream>

namespace animals {
    class Animal {
        std::string *name;

        public:
        Animal() : Animal("Undifined") {}

        Animal(std::string name) {
            this->name = new std::string(name);
        }

        std::string get_name() {
            return *(this->name);
        }

        ~Animal() {
            delete this->name;
        }
    };
}

class Reservoir {
    int lenght;
    int width;
    int height;
    animals::Animal *array;
    std::string name;
    int animals_size = 0;

    public:
    Reservoir() : Reservoir(5,5,5,"pool") {}

    //pool, river, sea
    Reservoir(int lenght,int width,int height,std::string name) {
        this->lenght = lenght;
        this->width = width;
        this->height = height;
        this->name = name;
        array = new animals::Animal[1];
        this->animals_size++;
    }

    explicit Reservoir(Reservoir &other) {
        this->lenght = other.lenght;
        this->width = other.width;
        this->height = other.height;
        this->name = other.name;
    }

    void print_V() const{
        std::cout << this->lenght * this->width * this->height << std::endl;
    }

    void print_S() const {
        std::cout << this->lenght * this->width << std::endl;
    }

    bool check(Reservoir &res) {
        if (this->name == res.name) {
            return true;
        }

        return false;
    }

    void add_new_animal(animals::Animal &animal) {
        animals::Animal *tmp = array;
        delete [] array;
        array = new animals::Animal[this->animals_size + 1];

        for (int i = 0 ; i < this->animals_size; i++) {
            array[i] = tmp[i];
        }

        delete [] tmp;

        array[this->animals_size] = animal;

        this->animals_size++;

    }

    void print_all() {
        for (int i = 0; i < this->animals_size; i++) {
            std::cout << this->array[i].get_name() << "  ";
        }

        std::cout << std::endl;
    }

    ~Reservoir() {
        //delete [] this->array;

        std::cout << std::endl << "Удалено !";
    }

};


int main() {

    Reservoir *test = new Reservoir(6,6,6,"river");

    animals::Animal *animal = new animals::Animal("tiger");

    test->print_V();
    
    test->print_S();

    test->add_new_animal(*animal);

    delete test;

    delete animal;

    return 0;
}
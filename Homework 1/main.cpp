#include <iostream>
#include <string>

namespace classes {
    class Person {

        std::string *name;
        std::string *surname;
        std::string *otchestvo;


        public:
        Person() : Person("Unfined","Unfined","Unfined") {}

        Person(std::string n,std::string s, std::string o) {
            this->name = new std::string(n);
            this->surname = new std::string(s);
            this->otchestvo = new std::string(o);
        }

        void info() {
            std::cout << *(this->name) << "  " << *(this->surname) << "  " << *(this->otchestvo) << std::endl;
        }

        std::string get_name() {
            return *(this->name);
        }

        ~Person() {
            delete this->name;
            delete this->surname;
            delete this->otchestvo;
        }
    };

    class Flat {
        int size = 0;

        std::string *name;
        Person *array = new Person[size];

        public:

        Flat() {}

        Flat(std::string name, Person &person) {
            this->name = new std::string(name);
            this->array = new Person[1];
            this->size++;
            array[this->size - 1] = person;
        }

        void add_person(Person &person) {
            this->size++;
            Person *tmp = this->array;
            this->array = new Person[this->size];
            for (int i = 0; i < this->size - 1; i++) {
                this->array[i] = tmp[i];
            }

            this->array[this->size - 1] = person;
        }
        void print_all() {
            for (int i = 0; i < this->size; i++) {
                std::cout << this->array[i].get_name() << std::endl;
            }

        }


        std::string get_name() {
            return *(this->name);
        }

        ~Flat() {
            delete this->name;
            //delete [] this->array;
        }

    };

    class House {

        std::string *name;
        int size = 0;
        Flat *array;

        public:

        House() {}

        House(std::string name,Flat &flat) {
            this->name = new std::string(name);
            this->array = new Flat[1];
            this->size++;
            array[this->size - 1] = flat;
        }

        void print() {
            for (int i = 0; i < this->size; i++) {
                std::cout << array[i].get_name() << "  ";
            }

            std::cout << std::endl;
        }

        std::string get_name() {
            return *(this->name);
        }

        void add_flat(Flat &flat) {
            this->size++;
            Flat *tmp = this->array;
            this->array = new Flat[this->size];
            for (int i = 0; i < this->size - 1; i++) {
                this->array[i] = tmp[i];
            }

            this->array[this->size - 1] = flat;

        }

        ~House() {
            delete this->name;
        }

    };
}

int main() {

    classes::Person person("Михаил","Петров","Иванович");

    person.info();

    std::cout << std::endl;

    classes::Flat flat("flat1",person);

    std::cout << flat.get_name();

    std::cout << std::endl;

    classes::House house("house1",flat);

    std::cout << house.get_name();

    return 0;
}
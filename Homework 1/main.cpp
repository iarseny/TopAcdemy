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
        Person *list;
        std::string *name;

        public:

        Flat(){

        }

        void change(std::string new_string) {
            delete name;
            name = new std::string(new_string);

        }

        void print() {
            for (int i = 0; i < size; i++) {
                std::cout << this->list[i].get_name() << "  ";
            }

            std::cout << std::endl;
        }

        void add_person(Person person) {
            Person *tmp = this->list;
            delete [] this->list;
            this->size++;
            this->list = new Person[this->size];
            for (int i = 0; i < size - 1; i++) {
                this->list[i] = tmp[i];
            }

            this->list[size - 1] = person;

        }

        std::string get_name() {
            return *(this->name);
        }

        Flat(std::string name,Person person) {
            this->name = new std::string(name);
            this->list = new Person[1];
            this->size++;
            this->list[size - 1] = person;
        }

        ~Flat() {
            delete [] this->list;
            delete this->name;
        }
    };

    class House {

        std::string *name;
        int size = 0;
        Flat *array;

        public:

        House(std::string name,Flat flat) {
            this->name = new std::string(name);
            array = new Flat[1];
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

        void add_flat(Flat flat) {
            Flat *tmp = this->array;
            delete [] this->array;
            this->size++;
            this->array = new Flat[this->size];
            for (int i = 0; i < size - 1; i++) {
                this->array[i] = tmp[i];
            }

            this->array[size - 1] = flat;

        }

        ~House() {
            delete [] this->array;
            delete this->name;
        }

    };
}

int main() {

    classes::Person person("Михаил","Петров","Иванович");

    std::cout << person.get_name();

    return 0;
}
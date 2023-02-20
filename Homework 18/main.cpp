#include <iostream>

class Student {
    std::string name;
    int med_marks;
    int year;
    std::string kollectiv;

    public:

    Student() : Student("none",0,0,"none") {}

    Student(std::string name, int m, int y, std::string k) {
        this->name = name;
        this->med_marks = m;
        this->year = y;
        this->kollectiv = k;
    }
};


class Aspirant : public Student {

    bool work;

    public:
    Apirant() : Student() {}

};

int main() {

    return 0;
}
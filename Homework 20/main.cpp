#include <iostream>
#include <string>

class Student {
    protected:
    std::string name;
    int age;
    int marks;

    public: 

    Student() {}
};

class Aspirant : public Student {
    int work_mark;

    public:

    Aspirant() : Aspirant("none", 0, 0, 0) {}

    Aspirant(std::string name, int age, int marks, int work_mark) {
        this->name = name;
        this->age = age;
        this->marks = marks;
        this->work_mark = work_mark;
    }

    std::string get_info() {
        std::string res = "";
        res += this->name + " " + std::to_string(this->age) + " " + std::to_string(this->marks) + " " + std::to_string(this->work_mark);

        return res;
    }
};

std::ostream &operator<<(std::ostream &out, Aspirant &aspirant) {
    out << aspirant.get_info();

    return out;
}

int main() {

    Aspirant aspirant("Анатолий", 18, 5, 5);

    std::cout << aspirant;

    return 0;
}
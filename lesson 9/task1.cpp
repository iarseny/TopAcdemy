#include <iostream>
#include <fstream>
#include <string>

class Calc {

public:

    Calc() {}

    int plus(int a, int b) {
        return a + b;
    }

    int minus(int a, int b) {
        return a - b;
    }

    ~Calc() {
        std::cout << std::endl << "Удалено !";
    }

};

class SuperCalc : public Calc {

    public:
    int mult(int a, int b) { // умножение
        return a * b;
    }

    int div(int a, int b) { // деление
        return a / b;
    }

};


class CalcFile : public SuperCalc {
    private:
        std::ofstream stream;

    public:

    CalcFile() {
        
        (this->stream).open("task.txt",std::ios::app);
    }

    void plus(int a, int b) {
        (this->stream) << std::to_string(this->SuperCalc::plus(a,b)) << "\n";
    }

    void minus(int a, int b) {
        (this->stream) << std::to_string(this->SuperCalc::minus(a,b)) << "\n";
    }

    void mult(int a, int b) {
        (this->stream) << std::to_string(this->SuperCalc::mult(a,b)) << "\n";
    }

    void div(int a, int b) {
        (this->stream) << std::to_string(this->SuperCalc::div(a,b)) << "\n";
    }

    ~CalcFile() {
        (this->stream).close();
    }

};

int main() {

    CalcFile file;

    file.plus(5,5);


    return 0;
}
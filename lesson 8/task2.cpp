#include <iostream>

class Task {

    int isprime(int num) {

        if ((num * num) % 24 == 1)
        {
            return true;
        }

        return false;
    }

    int first;
    int second;

    public:
    Task(int first,int second) {

        this->first = first;
        this->second = second;

    }

    void print() {
        int n = 0;
        int tmp = this->first;
        while(tmp <= this->second) {
            if (this->isprime(tmp) || tmp == 2 || tmp == 3) {
                n++;
                std::cout << tmp << " ";
            }
            tmp++;
        }

        std::cout << std::endl << n;
    }

};


int main() {

    Task task(3,13);

    task.print();

    return 0;
}
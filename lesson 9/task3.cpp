#include <iostream>
#include <string>
#include <fstream>

class Task {

    std::string res = "";

    public:

    Task() {
        while (true) {
            std::cout << "1)Прибавить\n2)Вычти\n3)Умножить\n4)Разделить\n5)Выйти\n";
            int choose;

            std::cin >> choose;
            if (choose == 5) {
                int choose;
                std::cout << std::endl << std::endl << "Выберете: 1)Выйти\n2)Сохранить\n";
                std::cin >> choose;
                if (choose == 2) {
                    std::ofstream write;
                    write.open("result.txt");

                    write << this->res;

                    write.close();
                }

                exit(0);
            } else {
                std::cout << "\n\nВведите два числа: \n";
                int a,b;
                std::cin >> a >> b;

                if (choose == 4) {
                    std::cout << this->dev(a,b) << "\n";
                    this->res += (std::to_string(this->dev(a,b)) + "\n");
                } else if (choose == 3) {
                    std::cout << this->multi(a,b) << "\n";
                    this->res += (std::to_string(this->multi(a,b)) + "\n");
                } else if (choose == 2) {
                    std::cout << this->minus(a,b) << "\n";
                    this->res += (std::to_string(this->minus(a,b)) + "\n");
                } else if (choose == 1) {
                    std::cout << this->plus(a,b) << "\n";
                    this->res += (std::to_string(this->plus(a,b)) + "\n");
                }

            }
        }
    }

    int plus(int a,int b) {
        return a + b;
    }

    int minus(int a,int b) {
        return a - b;
    }

    int multi(int a,int b) {
        return a * b;
    }

    int dev(int a, int b) {
        return a / b;
    }

};


int main() {

    Task task;

    return 0;
}
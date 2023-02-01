#include <iostream>
#include <typeinfo>

template<typename T>
class Matrix {
    int n;
    T *matrix;
    public:
    Matrix(bool random = false) {
        if (!random) {
            int n;
            std::cout << "Введи размер: \n";
            std::cin >> n;
            this->n = n;
            this->matrix = new T[n];
            for (int i = 0; i < n; i++) {
                std::cin >> this->matrix[i];
            }
        } else {
            int n;
            std::cout << "Введи размер: \n";
            std::cin >> n;
            this->n = n;

            this->matrix = new T[n];

            if (typeid(this->matrix).name() == "int") {

                srand(time(NULL));
                for (int i = 0; i < n; i++) {
                    this->matrix[i] = rand() % 10;
                }
            }
        }
    }

    Matrix &operator+(int g) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] += g;
        }

        return *this;
    }

    Matrix &operator-(int g) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] -= g;
        }

        return *this;
    }

    Matrix &operator*(int g) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] *= g;
        }

        return *this;
    }

    Matrix &operator/(int g) {
        for (int i = 0; i < this->n; i++) {
            this->matrix[i] /= g;
        }

        return *this;
    }

    void show() {
        for (int i = 0; i < this->n; i++) {
            std::cout << this->matrix[i] << "  ";
        }
    }


    ~Matrix() {
        delete [] this->matrix;
    }
};


int main() {
    Matrix<int> matrix;

    matrix.show();

    return 0;
}
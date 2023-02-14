#include <iostream>
#include <random>
#include <string>

class Task {
    int **array;
    int N;
    int M;

    public:
    Task() {
        std::cout << "Введите колличество столбцов: \n";

        std::cin >> this->N;

        std::cout << "Введите колличество строк: \n";

        std::cin >> this->M;

        this->array = new int *[this->N];
        for (int i = 0; i < this->N; i++) {
            this->array[i] = new int[this->M];
        }

        srand(time(NULL));

        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                this->array[i][j] = -85 + rand() % (85 + 85 + 1);
            }
        }
    }

    void show() {
        for (int i = 0; i < this->N; i++) {
            std::cout << std::to_string(i + 1) + ") ";
            for (int j = 0; j < this->M; j++) {
                std::cout << this->array[i][j] << " ";
            }

            std::cout << std::endl;
        }
    }


    ~Task() {
        for (int i = 0; i < N; i++){
            delete [] this->array[i];
        }

        delete [] this->array;
    }

    void median() {
        for (int i = 0; i < this->N; i++) {
            double sum = 0;
            for (int j = 0; j < this->M; j++) {
                sum += this->array[i][j];
            }

            std::cout << sum / this->M << std::endl;
        }
    }
};

int main() {

    Task task;

    task.show();

    std::cout << std::endl << std::endl;

    task.median();

    return 0;
}
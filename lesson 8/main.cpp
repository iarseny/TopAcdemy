#include <iostream>

class Task {
    int **arr;
    int x;
    int y;

    public:
    Task() {
        std::cout << "Введите x: " << std::endl;
        std::cin >> this->x;

        std::cout << "Введите y: " << std::endl;
        std::cin >> this->y;

        this->arr = new int*[x];
        for (int i = 0; i < this->x; i++) {
            this->arr[i] = new int[y];
        }
    }

    void fill(int one, int two) {
        srand(time(NULL));
        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                this->arr[i][j] = one + rand() % (two - one);
            }
        }

        std::cout << std::endl;
    }

    float argv() {
        float sum = 0;
        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                sum += this->arr[i][j];
            }
        }

        return sum / (this->x * this->y);
        
    }

    void show() {
        for (int i = 0; i < this->x; i++) {
            for (int j = 0; j < this->y; j++) {
                std::cout << this->arr[i][j] << " ";
            }
        }
    }

    ~Task() {
        for (int i = 0; i < this->x; i++) {
            delete [] this->arr[i];
        }

        delete [] this->arr;
    }
};

int main() {
    Task task;

    task.fill(5,25);

    task.show();

    std::cout << std::endl << task.argv();
}
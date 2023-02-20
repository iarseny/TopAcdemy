
#include <iostream>
// #include <exception>
#include <vector>

int input_n() {
    int n;
    std::cout << " : ";
    std::cin >> n;
    return n;
}

// Выбрсывает исключение
int print_n() {

    int n = input_n();

    if (n >= 10 && n <= 15) {
        std::cout << n << "\n";
    } else {
        throw "Число должно быть от 10 до 15!";
    }

    return n;
}

void print_all_del(int n) {

    for (int i = 1; i < n; ++i) {

        if (n % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}

void print_div(int n) {
    int m = input_n();

    if (m == 0) throw "На ноль делить нельзя!!!";

    std::cout << "Остаток от деления " << n % m << "\n";
}

void print_array(std::vector<int> &vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << " ";
    }

    std::cout << std::endl;
}

int search(std::vector<int> &vector) {
    int el;
    std::cin >> el;
    int index;
    bool right = false;
    for (int i = 0; i < vector.size(); i++) {
        if (vector[i] == el) {
            right = true;
            index = i;
            break;
        }
    }
    if (!right) {
        throw "no el";
    } else {
        return index;
    }

}


void chose_com(int n, std::vector<int> &vector) {

    int v;

    std::cout << "Выберите команду \n";
    std::cout << "1. Все делители \n";
    std::cout << "2. Остаток от деления \n";
    std::cout << "3. Показать массив \n";
    std::cout << "4. Поиск элемента \n";
    std::cout << "5. Удаление элемента по значению \n";
    std::cout << "6. Удаление элемента по индексу \n";
    std::cout << "7 : Выход \n";

    std::cin >> v;
    int index = 0;
    int el;
    switch (v)
    {
    case 1:
        print_all_del(n);
        break;
    case 2:
        print_div(n);
        break;

    case 3:
        print_array(vector);
        break;

    case 4:
        std::cout << search(vector) << "\n\n";
        break;

    case 5:
        std::cin >> el;
        for (int i = 0; i < vector.size(); i++) {
            if (vector[i] == el) {
                index = i;
            }
        }
        vector.erase(vector.begin() + index);
        print_array(vector);
        break;

    case 6:
        std::cin >> index;
        vector.erase(vector.begin() + index);
        print_array(vector);
        break;

    case 7:
        exit(0);
        break;
    default:
        break;
    }
}

int full_array(std::vector<int> &vector) {
    int n;
    std::cout << "Введите размер массива: \n";
    std::cin >> n;

    if (n >= 0) {

        for (int i = 0; i < n; i++) {
            int tmp;
            std::cin >> tmp;
            vector.push_back(tmp);
        }

    } else {
        throw "error while filling the array";
    }

    return n;
}

int main () {

    std::vector<int> vector;

    while (true) {
        try {
                std::cout << "Введите число от 10 до 15";
                int n = print_n();
                full_array(vector);
                chose_com(n,vector);

        } catch (const char* error) {

            if (error == "error while filling the array") {
                std::cout << "Нет,брат !Не пойдёт !\n\n";
            } else if (error == "no el") {
                std::cout << "Нет,брат !Не пойдёт !\n\n";
            } else {
                std::cout << "Ошибка!!!\n";
                std::cout << error << "\n";
            }
        }

    }
    std::cout << "End!!\n";

    //delete [] array;
    return 0;

}
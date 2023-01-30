#include <iostream>
#include <fstream>
#include <string>

void func(std::string file,int v,std::string message) {
    std::ifstream f;

    f.open(file);
    int n = 0;

    if (f.is_open()) {
        while(f.good()) {
            std::string d;
            std::getline(f,d);
            n++;
        }

    }

    //std::cout << n;

    std::string *array = new std::string[n];

    f.close();

    std::ifstream f2;

    f2.open(file);

    int count_tmp = 0;
    while (f2.good()) {
        std::string tmp;
        std::getline(f2,tmp);
        array[count_tmp] = tmp;
        count_tmp++;
    }

    f2.close();

    std::string result = "";

    //std::cout << n << "  " << v;

    if (v <= n) {

        std::string *tmp5 = array;

        //delete [] array;

        array = new std::string[n + 1];

        for (int i = 0; i < v - 1; i++) {
            array[i] = tmp5[i];
        }

        array[v - 1] = message;

        for (int j = v - 1; j < n; j++) {
            array[j + 1] = tmp5[j];
        }

    } else {

        std::string *tmp6 = array;

        //delete [] array;

        array = new std::string[v];

        //std::cout << n;

        for (int i = 0; i < n; i++) {
            array[i] = tmp6[i];
        }

        for (int j = n; j < v - 1; j++) {
            array[j] = "";
        } 

        array[v - 1] = message;

        //array[v - 1] = message;

        //array[v - 1] = message;

    }


    for (int i = 0 ; i < n + 1; i++) {
        if (i != n) {
            result += array[i] + "\n";
        } else {
            result += array[i];
        }
    }

    std::ofstream f3;

    f3.open(file);

    f3 << result;

    f3.close();

}


int main() {

    std::string text;
    int val;

    std::cout << "Введите строку: \n";

    std::cin >> val;

    std::cout << "Введите текст строки: \n";

    std::cin >> text;

    func("try1.txt",val,text);

    return 0;
}
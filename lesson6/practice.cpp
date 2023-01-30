#include <fstream>
#include <string>
#include <iostream>


int main() {

    std::ifstream f;

    std::cin.ignore();

    f.open("picture.txt",std::ios::app);

    std::string text;

    std::getline(f,text);

    std::cout << text;

    return 0;
}
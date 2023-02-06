#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>


int main() {

    std::ifstream stream_read;

    std::string main_string;

    stream_read.open("file1.txt");

    if (stream_read.is_open()) {
        while (stream_read.good()) {
            std::string tmp = "";
            std::getline(stream_read,tmp);
            main_string += tmp + "\n";
        }
    }


    stream_read.close();

    char glassnie[10];

    int n = std::count(main_string.begin(), main_string.end(), '\n');

    int size = main_string.length() - n;

    n--;

    std::cout << size;

    std::cout << n;

    return 0;
}
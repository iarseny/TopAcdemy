#include <iostream>
#include <fstream>
#include <string>



int main() {

    std::ifstream stream_read;

    std::string main_string;

    stream_read.open("file3.txt");

    if (stream_read.is_open()) {
        while (stream_read.good()) {
            std::string tmp = "";
            std::getline(stream_read,tmp);
            main_string += tmp + "\n";
        }
    }

    stream_read.close();

    int size = main_string.length() - 1;

    char checking [size];

    for (int i = 0; i < size; i++) {
        checking[i] = main_string[i];
    }

    int n = 0;

    for (int g = 0; g < size; g++) {
        if (checking[g] == '\n') {
            n++;
        }
    }

    char glassnie_arr[] = {'a','e','i','o','u','y'};

    int glassnie_count = 0;

    for (int i = 0; i < size; i++) {
        for (int w = 0; w < 6; w++) {
            if ()
        }
    }
    



    int sogl_count = 0;


    std::cout << n;

    return 0;
}
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

    int n = std::count(main_string.begin(), main_string.end(), '\n');

    int size = main_string.length() - n;

    n--;

    int glassnie_count = 0;
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'a');
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'e');
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'i');
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'o');
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'u');
    glassnie_count += std::count(main_string.begin(), main_string.end(), 'y');



    int sogl_count = 0;

    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');
    sogl_count += std::count(main_string.begin(), main_string.end(), 'a');


    std::cout << glassnie_count;

    return 0;
}
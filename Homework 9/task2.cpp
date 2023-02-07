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

    int size = main_string.length();

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
            if (checking[i] == glassnie_arr[w] || checking[i] == toupper(glassnie_arr[w])) {
                glassnie_count++;
            }
        }
    }
    
    char sogl_arr[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};


    int sogl_count = 0;

    for (int i = 0; i < size; i++) {
        for (int w = 0; w < 21; w++) {
            if (checking[i] == sogl_arr[w] || checking[i] == toupper(sogl_arr[w])) {
                sogl_count++;
            }
        }
    }

    char numbers[] = {'0','1','2','3','4','5','6','7','8','9'};
    int numbers_count = 0;

    for (int i = 0; i < size; i++) {
        for (int w = 0; w < 10; w++) {
            if (checking[i] == numbers[w]) {
                numbers_count++;
            }
        }
    }

    size--;

    std::ofstream str;

    str.open("answer.txt");

    std::string answer_string = "1)" + std::to_string(size) + "\n" + "2)" + std::to_string(n) + "\n" + "3)" + std::to_string(glassnie_count) + "\n" + "4)" + std::to_string(sogl_count) + "\n" + "5)" + std::to_string(numbers_count); 

    str << answer_string;

    return 0;
}
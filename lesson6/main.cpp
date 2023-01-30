#include <iostream>
#include <fstream>
#include <string>


void read_all_file(std::string filename) {
    std::ifstream fin;

    fin.open(filename);

    if (fin.is_open()) {
        std::string text;

        while (fin.good())
        {
            std::getline(fin,text);
            std::cout << text << std::endl;
        }
        
    } else {
        std::cout << "Can't read file";
    }

    fin.close();
}


int main() {
    //std::string file;

    //std::ifstream fin;

    //fin.open("test.txt");

    //fin.close();

    //fin >> file;

    //std::getline(fin, file);

    //std::cout << file;

    read_all_file("test.txt");

    return 0;
}
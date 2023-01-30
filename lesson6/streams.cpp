#include <iostream>
#include <fstream>
#include <string>

void write_in_file() {
    std::ofstream fout;

    fout.open("hello.txt",std::ios::app);
    //Запись в конец

    fout << "еееv";

    fout.close();
}


int main() {

    write_in_file();

    return 0;
}
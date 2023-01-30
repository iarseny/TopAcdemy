#include <iostream>
#include <fstream>
#include <string>

void func(std::string in_file,std::string into_file) {
    std::ifstream f;

    f.open(in_file);
    std::string res = "";

    if (f.is_open()) {
        while(f.good()) {
            std::string tmp;
            std::getline(f,tmp);

            res += tmp + "\n";
        }

    }

    f.close();

    std::ofstream f2;

    f2.open(into_file);

    if(f2.is_open()) {
        f2 << res;
    }

    f2.close();

}


int main() {

    func("try1.txt","try2.txt");

    return 0;
}
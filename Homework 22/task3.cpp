#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Reader {
    std::map<int, std::string> m;
    public:
    Reader() {}

    std::string read() {
        std::string res = "";
        std::ifstream read;

        read.open("save.txt");

        if (read.is_open()) {
            while (read.good()) {
                std::string tmp;
                std::getline(read, tmp);
                res += tmp + "\n";
            }
        }

        read.close();

        this->m[0] = res;

        return res;
    }

    int get_slov() {
        std::string find = this->read();

        int slov = 1;

        for (int i = 0; i < find.size(); i++) {
            if (find[i] == ' ' || find[i] == '\n') {
                slov++;
            }

        }

        this->m[1] = std::to_string(slov);

        return slov;
    }

    int the_most_times() {
        std::string str = this->read();
        std::istringstream input{ str };
        std::vector<std::string> result;

        while (!input.eof()) {
            std::string substring;
            input >> substring;
            result.push_back(substring);
        }

        std::map<std::string, int> strings;

        for (int i = 0; i < result.size(); i++) {
            strings[result[i]] = 0;
        }

        for (int i = 0; i < result.size(); i++) {
            strings[result[i]]++;
        }

        int max = 0;
        for (int i = 0; i < result.size(); i++) {
            if (strings[result[i]] > max) {
                max = strings[result[i]];
            }
        }

        this->m[2] = std::to_string(max);

        return max;
    }

    ~Reader() {
        std::ofstream write;

        write.open("res.txt");

        write << this->m[0] << "\n" << this->m[1] << "\n" << this->m[2];

        write.close();
    }
};

int main() {
    Reader read;

    std::cout << read.read();

    std::cout << read.get_slov();

    std::cout << read.the_most_times();

    return 0;
}
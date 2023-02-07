#include <iostream>
#include <fstream>

class FilePars {
    std::string file_name;

    public:

    FilePars() : FilePars("default.txt") {}

    FilePars(const FilePars &file) : FilePars(file.file_name) {}

    FilePars(std::string filename) {
        this->file_name = filename;
    }

    std::string getFileContent() {
        std::ifstream str;
        std::string res;
        str.open(this->file_name);

        if (str.is_open()) {
            while (str.good()) {
                std::string tmp;
                std::getline(str,tmp);
                res += tmp + "\n";
            }
        }

        str.close();
        
        return res;
    }

    std::string getFileLine(int n_line) {
        std::ifstream str;
        std::string *res;
        int size = 0;
        str.open(this->file_name);

        if (str.is_open()) {
            while (str.good()) {
                std::string tmp;
                std::getline(str,tmp);
                size++;
            }
        }
        str.close();

        std::ifstream str2;

        str2.open(this->file_name);

        res = new std::string[size];
        int w = 0;
        if (str2.is_open()) {
            while (str2.good()) {
                std::string tmp;
                std::getline(str2,tmp);
                res[w] = tmp;
                w++;
            }
        }

        std::string result = res[n_line - 1];

        delete [] res;
        str2.close();

        return result;
    }

    void insertLineEnd(std::string line) {
        std::string string_last = this->getFileContent();
        std::ofstream stream;

        stream.open(this->file_name);

        stream << (string_last + line);

        stream.close();
    }

    void insertLine(int n_line,std::string line) {

        std::ifstream str;
        int size = 0;
        str.open(this->file_name);

        if (str.is_open()) {
            while (str.good()) {
                std::string tmp;
                std::getline(str,tmp);
                size++;
            }
        }

        str.close();

        if (n_line <= size) {
            std::string *res;
            std::ifstream str2;

            str2.open(this->file_name);

            res = new std::string[size];
            int w = 0;
            if (str2.is_open()) {
                while (str2.good()) {
                    std::string tmp;
                    std::getline(str2,tmp);
                    res[w] = tmp;
                    w++;
                }
            }

            str2.close();

            std::string *new_res = new std::string[size + 1];

            for (int i = 0; i < n_line - 1; i++) {
                new_res[i] = res[i];
            }

            new_res[n_line - 1] = line;

            for (int h = n_line - 1; h < size; h++) {
                new_res[h + 1] = res[h];
            }

            delete [] res;

            std::string final_string = "";

            for (int q = 0; q < size + 1; q++) {
                if (q != size) {
                    final_string += (new_res[q] + "\n");
                } else {
                    final_string += new_res[q];
                }
            }

            delete [] new_res;

            std::ofstream write_file;

            write_file.open(this->file_name);

            write_file << final_string;


            write_file.close();

        } else {
            std::string last_string = this->getFileContent();

            for (int i = 0; i < n_line - size - 1; i++) {
                last_string += "\n";
            }

            last_string += line;

            std::ofstream write;

            write.open(this->file_name);

            write << last_string;
        }
    }

};

int main() {

    FilePars file;

    std::cout << file.getFileContent();

    std::cout << std::endl;

    std::cout << file.getFileLine(2);

    std::cout << std::endl << std::endl;

    //file.insertLineEnd("Mbappe 10");

    file.insertLine(8,"hello");

    file.insertLine(2,"goodbye");

    //std::cout << file.getFileContent();

    return 0;
}
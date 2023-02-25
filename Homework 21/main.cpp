#include <iostream>
#include <vector>

class Passport {
    protected:
    std::string name;
    int born;
    std::string street;
};

class ForeignPassport : public Passport {
    std::vector<std::string> vec;
    int passport;

    public:
    ForeignPassport() : ForeignPassport("none",0,"none",0) {}

    ForeignPassport(std::string name, int born, std::string street, int passport) {
        this->name = name;
        this->born = born;
        this->street = street;
        this->passport = passport;
    }

    void add_visa(std::string v) {
        this->vec.push_back(v);
    }

    void print_visa() {
        std::vector<std::string>::iterator iter = this->vec.begin();

        for (iter; iter < vec.end(); iter++) {
            std::cout << *iter << " ";
        }
    }
    
    friend std::ostream &operator<<(std::ostream &out, ForeignPassport &f) {

        out << f.name << " " << f.born << " " << f.passport << " " << f.street << " " << f.street;

        return out;
    }
};


int main() {

    ForeignPassport f;

    std::cout << f;

    std::cout << std::endl;

    f.add_visa("1");

    f.print_visa();

    return 0;
}
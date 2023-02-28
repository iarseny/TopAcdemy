#include <iostream>
#include <fstream>

class Spravochnik {
    std::string name;
    std::string v;
    int phone;
    std::string adress;
    std::string deatel;
    int size = 1;
    Spravochnik *s;

    public:
    Spravochnik(std::string name, std::string v, int phone, std::string adress, std::string deatel) {
        this->name = name;
        this->v = v;
        this->phone = phone;
        this->adress = adress;
        this->deatel = deatel;
    }

    Spravochnik() : Spravochnik("none", "none", 0, "none", "none") {}

    Spravochnik(const Spravochnik &spr) {
        this->s = new Spravochnik[1];
        this->s[0] = spr;
    }

    void add(const Spravochnik &spr) {
        this->size++;
        Spravochnik *tmp = this->s;

        this->s = new Spravochnik[this->size];

        for (int i = 0; i < this->size - 1; i++) {
            this->s[i] = tmp[i];
        }

        this->s[this->size - 1] = spr;
    }

    int search_for_name(std::string name) {
        for (int i = 0; i < this->size; i++) {
            if (this->s[i].name == name) {
                return i;
            }
        }
    }

    int search_for_v(std::string v) {
        for (int i = 0; i < this->size; i++) {
            if (this->s[i].v == v) {
                return i;
            }
        }
    }

    int search_for_phone(int p) {
        for (int i = 0; i < this->size; i++) {
            if (this->s[i].phone == p) {
                return i;
            }
        }
    }

    int search_for_d(std::string d) {
        for (int i = 0; i < this->size; i++) {
            if (this->s[i].deatel == d) {
                return i;
            }
        }
    }

    void show() {
        for (int i = 0; i < this->size; i++) {
            std::cout << "\n" << this->s[i].name;
        }
    }

    void save_to_file() {
        std::ofstream file;
        file.open("save.txt");
        std::string res = "";
        for (int i = 0; i < this->size; i++) {
            res += "\n" + this->s[i].name;
        }

        file << res;

        file.close();

    }
};

int main() {

    Spravochnik s1;
    Spravochnik s2(s1);

    s2.save_to_file();

    return 0;
}
#include <iostream>

class String {
    std::string q;
    public:
    String(std::string str) {
        this->q = str;
    }

    String () {}

    String(const String &string) : String(string.q){}

    String &operator=(const String &string) {
        this->q = string.q;

        return *this;
    }

    int get_length() {
        return this->q.length();
    }

    void clear() {
        this->q = "";
    }

    ~String() {
        std::cout << "\nУдалено !";
    }

    std::string operator+(const String &string) {
        return this->q + string.q;
    }

    String &operator+=(const String &string) {

        this->q += string.q;

        return *this;
    }

    bool operator==(const String &string) {
        if (this->q == string.q) {
            return true;
        }

        return false;
    }

    bool operator!=(const String &string) {
        if (this->q != string.q) {
            return false;
        }

        return true;
    }
};

int main() {

    String string1("qqq");

    String string2("www");

    std::cout << string1 + string2;

    return 0;
}
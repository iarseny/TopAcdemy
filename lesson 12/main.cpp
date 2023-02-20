#include <iostream>

void check() {
    throw "нет";
}

int main() {

    try {
        check();
    } catch (const char *error) {
        
    }


    return 0;
}
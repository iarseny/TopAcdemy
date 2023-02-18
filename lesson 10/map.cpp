#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> map;

    map["a"] = 12;

    std::map<std::string, int>::iterator iter = map.begin();

    std::cout << map["a"] << "  " << iter->first;



    return 0;
}
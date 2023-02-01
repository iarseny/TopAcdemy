#include <list>
#include <iostream>

int main() {

    std::list<int> lists = {1,2,3};

    std::cout << lists.front() + 2;

    lists.push_back(5);
    

    return 0;
}
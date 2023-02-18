#include <iostream>
#include <set>



int main() {

    std::set<int> arr;

    arr.insert(5);

    std::set<int>::iterator iter;

    for (iter = arr.begin(); iter != arr.end(); iter++) {
        std::cout << *iter << " ";
    }


    return 0;
}
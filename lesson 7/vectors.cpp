#include <iostream>
#include <vector>


int main() {
    std::string arr[5] = {"1","2","3","4","5"};

    std::vector<std::string> vector_array(&(arr[0]),&(arr[5]));

    std::vector<std::string>::iterator iter = vector_array.begin() + 1;

    
    std::cout << (*iter) << "  " << vector_array[2];

    return 0;
}
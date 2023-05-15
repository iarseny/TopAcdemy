#include <iostream>

using namespace std;

int length(int n) {
    int l = 1;
    while (n / 10 != 0) {
        l++;
        n /= 10;
    }

    return l;
}

char* task(int n) {
    char *arr= new char[length(n) + 1];
    arr[length(n)] = '\0';
    int i = length(n) - 1;
    while (n) {
        arr[i] = n % 10 + '0';
        n /= 10;
        i--;
    }

    return arr;
}


int main() {

    int number;
    cin >> number;

    cout << task(number);
    return 0;
}
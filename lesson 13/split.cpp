#include <iostream>
#include <vector>

using namespace std;

void vector_cout(vector<string> str) {
    for (auto i : str) {
        cout << i << endl;
    }
}

vector<string> f(string str, char sep, int n = 0, string tmp = "", vector<string> res = vector<string> ()) {
    if (n == str.size()) {
        res.push_back(tmp);
        return res;
    }

    if (str[n] == sep) {
        tmp != "" ? res.push_back(tmp) : void ();
        tmp = "";
        return f(str, sep, n + 1, tmp, res);
    } else {
        tmp += str[n];
        return f(str, sep, n + 1, tmp, res);
    }
}


int main() {

    string s = "Hello      my       bro";
    char sep = ' ';


    vector_cout(f(s, sep));

    return 0;
}
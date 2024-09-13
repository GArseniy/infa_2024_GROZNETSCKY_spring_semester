#include <iostream>

using namespace std;

int main() {
    string s;

    while (cin >> s) {
        unsigned int i = 0;
        while (s[i] == '3' || s[i] == '4') {
            i++;
        }
        while (s[i] == '1' || s[i] == '2') {
            i++;
        }

        if (i == s.size()) {
            cout << '1' << endl;
        } else {
            cout << '0' << endl;
        }
    }

    return 0;
}
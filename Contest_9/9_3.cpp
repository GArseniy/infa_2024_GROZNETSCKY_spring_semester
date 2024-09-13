#include <iostream>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        unsigned int i = 0;
        unsigned int n = 0;
        unsigned int m = 0;
        while (s[i] == 'a') {
            n++;
            i++;
        }

        while (s[i] == '0') {
            m++;
            i++;
        }
        if (!n || !m) {
            cout << '0' << endl;
            continue;
        }

        unsigned n_b = 0;
        unsigned m_1 = 0;
        while (s[i] == 'b') {
            n_b++;
            i++;
        }

        while (s[i] == '1') {
            m_1++;
            i++;
        }
        if (n != n_b || m != m_1) {
            cout << '0' << endl;
            continue;
        }
        if (i == s.size())
            cout << '1' << endl;
        else {
            cout << '0' << endl;
        }
    }
    return 0;
}
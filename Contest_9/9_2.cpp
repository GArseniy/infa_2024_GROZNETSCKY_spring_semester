#include <iostream>

using namespace std;

int main() {
    char c;
    cin >> noskipws;
    std::cin.tie(0);

    while (cin >> c) {
        bool is_l = true;
        bool space = true;
        bool is_eof = false;
        unsigned int k = 0;
        unsigned int m = 0;
        while (c == '0') {
            space = false;
            k++;
            if (!(cin >> c)) {
                is_eof = true;
                break;
            }
        }

        while (c == '1') {
            space = false;
            m++;
            if (!(cin >> c)) {
                is_eof = true;
                break;
            }
        }

        if (!k || !m) {
            is_l = false;
        }

        while (!isspace(c) && !is_eof) {
            unsigned int k_tmp = 0;
            unsigned int m_tmp = 0;

            while (c == '0') {
                space = false;
                k_tmp++;
                if (!(cin >> c)) {
                    is_eof = true;
                    break;
                }
            }
            if (k_tmp != k) {
                is_l = false;
            }

            while (c == '1') {
                space = false;
                m_tmp++;
                if (!(cin >> c)) {
                    is_eof = true;
                    break;
                }
            }

            if (m_tmp != m) {
                is_l = false;
            }

            if (!(c == '0' || c == '1' || isspace(c)) && !is_eof) {
                is_l = false;

                while (!isspace(c)) {
                    space = false;
                    if (!(cin >> c)) {
                        is_eof = true;
                        break;
                    }
                }
            }
        }

        if (!space) {
            if (is_l) {
                cout << '1' << endl;
            } else {
                cout << '0' << endl;
            }
        }
    }

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
    string l, r;

    bool is_s = false;
    bool isnt_empty = false;
    bool has_only_s = false;
    bool is_ks = true;
    bool is_nks = true;
    bool r_s = false;
    bool eps = false;

    while (cin >> l >> r) {
        bool term = true;
        bool is_only_s = true;
        isnt_empty = true;

        for (size_t i = 0; i < l.size(); i++) {
            if (l[i] == 'S') {
                is_s = true;
                term = false;
            } else {
                is_only_s = false;
                if (l[i] >= 'A' && l[i] <= 'Z') {
                    term = false;
                } else {
                    is_ks = false;
                }
            }
        }
        if (l.size() > r.size()) {
            is_ks = false;
        }
        if (is_only_s) {
            has_only_s = true;
        }
        if (term) {
            cout << -1 << endl;
            return 0;
        }

        for (size_t i = 0; i < r.size(); i++) {
            if (r[i] == '_') {
                eps = true;
                if (!is_only_s) {
                    is_nks = false;
                }
            } else if (l[i] == 'S') {
                r_s = true;
            }
        }
    }

    if (eps && r_s) {
        is_nks = false;
    }

    if (!is_s || !isnt_empty || !has_only_s) {
        cout << -1;
    } else if (is_ks) {
        cout << 2;
        if (is_nks) {
            cout << 3;
        }
    } else {
        cout << 10;
    }

    cout << endl;

    return 0;
}
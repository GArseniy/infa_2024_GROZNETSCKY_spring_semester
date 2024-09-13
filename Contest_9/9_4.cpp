// S -> aQd
// Q -> aQd|P
// P -> bRc
// R -> bRc|_

#include <iostream>

using namespace std;

void R(int cnt, int bc) {
    if (bc > 0) {
        cout << 'b';
        R(cnt - 2, bc - 1);
        cout << 'c';
    }
}

void P(int cnt, int bc) {
    cout << 'b';
    R(cnt, bc - 1);
    cout << 'c';
}

void Q(int cnt, int ad) {
    if (ad > 0) {
        cout << 'a';
        Q(cnt - 2, ad - 1);
        cout << 'd';
    } else {
        P(cnt, cnt / 2);
    }
}

void S(int cnt) {
    int cnt_ad = (cnt - 2) / 2 - 1;
    while (cnt_ad >= 0) {
        cout << 'a';
        Q(cnt - 2, cnt_ad);
        cout << 'd' << endl;
        cnt_ad--;
    }
}

int main() {
    int k;
    cin >> k;
    if (k >= 4 && ((k % 2) == 0)) {
        S(k);
    }

    return 0;
}
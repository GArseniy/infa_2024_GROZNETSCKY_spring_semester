#include <iostream>
#include <vector>
#include <map>


using sparse_matrix = std::map<unsigned, std::map<unsigned, unsigned>>;
using ull = unsigned long long int;


enum {
    MOD = 0xFFFFFF79
};


int main() {
    unsigned r, c, v;

    sparse_matrix a;
    while ((std::cin >> r >> c >> v) and not(r == 0 && c == 0 && v == MOD)) {
        a[r][c] = v % MOD;
    }

    sparse_matrix b;
    while ((std::cin >> r >> c >> v) and not(r == 0 && c == 0 && v == MOD)) {
        b[r][c] = v % MOD;
    }

    for (const auto &i: b) {
        for (const auto &j: i.second) {
            a[i.first][j.first] = (ull(a[i.first][j.first]) + j.second) % MOD;
        }
    }

    for (const auto &i: a) {
        for (const auto &j: i.second) {
            if (j.second == 0) continue;
            std::cout << i.first << ' ' << j.first << ' ' << j.second << '\n';
        }
    }

    return 0;
}

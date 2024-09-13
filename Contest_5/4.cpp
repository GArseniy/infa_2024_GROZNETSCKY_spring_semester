#include <iostream>
#include <vector>
#include <map>


class SparseMatrix {
    static constexpr u_int32_t MOD = 4294967161;
    std::map<u_int32_t, std::map<u_int32_t, u_int32_t>> data = {};
public:
    SparseMatrix &operator+=(SparseMatrix &m) {
        for (const auto &r: m.data)
            for (const auto &c: r.second)
                data[r.first][c.first] = (data[r.first][c.first] + u_int64_t(c.second)) % MOD;
        return *this;
    }

    SparseMatrix &read() {
        u_int64_t r, c, v;
        while ((std::cin >> r >> c >> v) and not(r == 0 && c == 0 && v == MOD))
            data[r][c] = v % MOD;
        return *this;
    }

    void print() {
        for (const auto &r: data)
            for (const auto &c: r.second)
                if (c.second != 0)
                    std::cout << r.first << " " << c.first << " " << c.second << std::endl;
    }
};


int main() { (SparseMatrix().read() += SparseMatrix().read()).print(); }

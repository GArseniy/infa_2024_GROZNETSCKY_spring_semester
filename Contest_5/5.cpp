#include <iostream>
#include <vector>
#include <map>

struct Matrix {
    static constexpr u_int32_t MOD = 4294967161;
    std::map<u_int32_t, std::map<u_int32_t, u_int32_t>> data = {};

    Matrix &read() {
        u_int64_t r, c, v;
        while (std::cin >> r >> c >> v and not(r == 0 && c == 0 && v == MOD)) data[r][c] = v % MOD;
        return *this;
    }

    void print() {
        for (const auto &r: data)
            for (const auto &c: r.second)
                if (c.second) std::cout << r.first << " " << c.first << " " << c.second << std::endl;
    }
};

Matrix operator*(Matrix &m1, Matrix &m2) {
    Matrix m;
    for (auto &i: m1.data)
        for (auto &k: i.second)
            for (auto &j: m2.data[k.first])
                m.data[i.first][j.first] = (m.data[i.first][j.first] + (u_int64_t(k.second) * j.second)) % Matrix::MOD;
    return m;
}

int main() {
    Matrix  A = Matrix().read(),
            B = Matrix().read();
    (A * B).print();
}

#include <iostream>
#include <array>


class Matrix {
    enum {
        MATRIX_SIZE = 3
    };

    using double_matrix = std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE>;
    double_matrix m{};
public:
    Matrix() {
        m = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    }

    double &operator[](int i, int j) {
        return m[i][j];
    }

    using iterator = double_matrix::iterator;

    inline iterator begin() noexcept { return m.begin(); }

    inline iterator end() noexcept { return m.end(); }

};

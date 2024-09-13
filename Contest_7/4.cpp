#include <algorithm>
#include <iostream>

namespace Game {
    template<typename T>
    struct Coord {
        typedef T value_type;
        value_type row, col;

        Coord(T r = {}, T c = {}) : row(r), col(c) {}
    };

    template<typename T>
    size_t dist(Coord<T> size, Coord<T> p1, Coord<T> p2) {
        if (size.row < std::max(p1.row, p2.row) or size.col < std::max(p1.col, p2.col)) return 0;

        if (p1.col > p2.col) std::swap(p1, p2);
        if ((p1.col % 2) && !(p2.col % 2)) ++p2.row;
        p2.col -= p1.col;
        p1.col = 0;

        T diff = std::min(p1.row, p2.row);
        p2.row -= diff;
        p1.row -= diff;

        if (p1.row == 0)
            if (p2.row * 2 - 1 <= p2.col)
                return p2.col;
            else
                return p2.row + p2.col - (p2.col + 1) / 2;
        else if (p1.row * 2 + 1 <= p2.col)
            return p2.col;

        return p1.row - p2.col / 2 + p2.col;
    }
}

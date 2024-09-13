#include <iostream>
#include <iomanip>

class Point {
  public:
    int x = 0, y = 0;
    Point() {
        std::cin >> x >> y;
    }
};

class Line {
  public:
    double a, b, c;
    Line(const Point & A, const Point & B) {
        a = A.y - B.y;
        b = B.x - A.x;
        c = A.x * B.y - B.x * A.y;
    }
};

int is_parallel(const Line & L1, const Line & L2) {
    if ((L1.a == L2.a && L1.b == L2.b) || L1.a / L2.a == L1.b / L2.b) {
        if (L1.a / L2.a == L1.c / L2.c || (L1.c == 0 && L2.c == 0)) {
            std::cout << 2 << std::endl;
            return 1;
        }
        std::cout << 0 << std::endl;
        return 1;
    }
    std::cout << 1 << ' ';
    return 0;
}

void cross(const Line & L1, const Line & L2) {
    double x, y;
    if (L1.c * L2.b - L2.c * L1.b == 0) {
        x = 0;
    } else {
        x = -((L1.c * L2.b - L2.c * L1.b) / (L1.a * L2.b - L2.a * L1.b));
    }
    if (L1.a * L2.c - L2.a * L1.c == 0) {
        y = 0;
    } else {
        y = -((L1.a * L2.c - L2.a * L1.c) / (L1.a * L2.b - L2.a * L1.b));
    }
    std::cout << std::fixed;
    std::cout << std::setprecision(5) << x << ' ' << y << std::endl;
}

int main() {
    Point A1, B1, A2, B2;

    Line L1(A1, B1);
    Line L2(A2, B2);

    if (is_parallel(L1, L2)) {
        return 0;
    }

    cross(L1, L2);

    return 0;
}
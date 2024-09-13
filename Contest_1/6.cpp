#include <iostream>
#include <cmath>


const double PRECISION = 1E-5;


class Point {
public:
    double x, y;

    explicit Point(double x = 0, double y = 0) : x(x), y(y) {}
};


class Line { // Ax + By + C = 0
public:
    double a, b, c;

    explicit Line(Point p1, Point p2) {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
    }
};


bool is_parallel(Line l1, Line l2) {
    return fabs(l1.a * l2.b - l1.b * l2.a) < PRECISION;
}


bool is_equal(Line l1, Line l2) {
    return fabs(l1.a * l2.b - l1.b * l2.a) < PRECISION and
           fabs(l1.c * l2.a - l2.c * l1.a) < PRECISION;
}


Point lines_inter(Line l1, Line l2) {
    double x = -(l1.c * l2.b - l2.c * l1.b) / (l1.a * l2.b - l2.a * l1.b);
    double y = -(l1.a * l2.c - l2.a * l1.c) / (l1.a * l2.b - l2.a * l1.b);
    return Point(x, y);
}


enum mode {
    PARALLEL = 0,
    INTER = 1,
    EQUAL = 2

};

enum {
    POINT_CNT = 4
};


int main() {
    auto p = new Point[POINT_CNT];

    for (int i = 0; i < POINT_CNT; ++i) {
        std::cin >> p[i].x >> p[i].y;
    }

    Line l1 = Line(p[0], p[1]);
    Line l2 = Line(p[2], p[3]);

    if (is_equal(l1, l2)) {
        std::cout << EQUAL << std::endl;
    } else if (is_parallel(l1, l2)) {
        std::cout << PARALLEL << std::endl;
    } else {
        std::cout << INTER << std::endl;
        Point inter = lines_inter(l1, l2);
        std::cout << inter.x << ' ' << inter.y << std::endl;
    }
}

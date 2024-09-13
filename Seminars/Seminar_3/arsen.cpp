#include <iostream>

using namespace std;

class C {
    double x, y;

public:
    C(double a = 0, double b = 0) {
        x = a;
        y = b;
    }

// C '+'..
    C operator+(C abc) {
        C tmp(x + abc.x, y + abc.y);
        return tmp;
    }

// int x '+'
    friend double operator+(int x, C abc) {
        return (double(x) + abc.x + abc.y);
    }

    double operator~() const {
        return (-x - y);
    }

    C operator&(const C *a) {
        return C(0, 0);
    }

    C &operator++() {
        x += 1;
        return *this;
    }

    int friend operator*(const C &c1, C *c2) {
        return c1.x * c2->x;
    }

    C(const C *pc){}
};


C func1(const C &v1, int v2) {
    return C(v2 + v1, ~v1);
}

void func2(const C *p1, double p2) {
    C v1 = p2;
    C v2[2][2];
    C v3 = func1(func1(func1(&p1[3], p2), ~p1[2]), ++v1 * v2[1]);
}

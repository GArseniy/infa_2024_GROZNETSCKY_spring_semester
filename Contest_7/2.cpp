#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>


class Rectangle : public Figure {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    double get_square() const { return w * h; }

    static Figure *make(const std::string &data) {
        std::istringstream ss(data);
        double w, h;
        ss >> w >> h;
        return new Rectangle(w, h);
    }
};

class Square : public Figure {
    double a;
public:
    Square(double a) : a(a) {}

    double get_square() const { return a * a; }

    static Figure *make(const std::string &data) {
        std::istringstream ss(data);
        double x;
        ss >> x;
        return new Square(x);
    }
};

class Circle : public Figure {
    double r;
public:
    Circle(double r) : r(r) {}

    double get_square() const { return M_PI * r * r; }

    static Figure *make(const std::string &data) {
        std::istringstream ss(data);
        double x;
        ss >> x;
        return new Circle(x);
    }
};

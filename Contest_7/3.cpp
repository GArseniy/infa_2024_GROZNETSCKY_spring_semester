#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <functional>


class Figure {
public:
    virtual ~Figure() = default;

    [[nodiscard]] virtual double get_square() const = 0;

    [[nodiscard]] virtual std::string to_string() const = 0;
};


class Rectangle : public Figure {
    double w, h;
public:
    Rectangle(double w, double h) : w(w), h(h) {}

    [[nodiscard]] double get_square() const override { return w * h; }

    [[nodiscard]] std::string to_string() const override { return "R " + std::to_string(w) + " " + std::to_string(h); }

    static std::unique_ptr<Figure> make(const std::string &data) {
        std::istringstream ss(data);
        double w, h;
        ss >> w >> h;
        return std::make_unique<Rectangle>(w, h);
    }
};


class Square : public Figure {
    double a;
public:
    explicit Square(double a) : a(a) {}

    [[nodiscard]] double get_square() const override { return a * a; }

    [[nodiscard]] std::string to_string() const override { return "S " + std::to_string(a); }

    static std::unique_ptr<Figure> make(const std::string &data) {
        std::istringstream ss(data);
        double x;
        ss >> x;
        return std::make_unique<Square>(x);
    }
};


class Circle : public Figure {
    double r;
public:
    explicit Circle(double r) : r(r) {}

    [[nodiscard]] double get_square() const override { return M_PI * r * r; }

    [[nodiscard]] std::string to_string() const override { return "C " + std::to_string(r); }

    static std::unique_ptr<Figure> make(const std::string &data) {
        std::istringstream ss(data);
        double x;
        ss >> x;
        return std::make_unique<Circle>(x);
    }
};


class FigureFactory {
    FigureFactory() = default;

    ~FigureFactory() = default;

public:
    FigureFactory(const FigureFactory &) = delete;

    FigureFactory &operator=(const FigureFactory &) = delete;

    static FigureFactory &factory_instance() {
        static FigureFactory instance;
        return instance;
    }

    std::unique_ptr<Figure> make_figure(const std::string &type, const std::string &data) {
        std::map<std::string, std::function<std::unique_ptr<Figure>(const std::string &x)>> m = {
                {"R", Rectangle::make},
                {"S", Square::make},
                {"C", Circle::make}};

        return m[type](data);
    }
};


class FigureVec : std::vector<std::unique_ptr<Figure>> {
public:
    FigureVec &read() {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);
            std::string type, data;
            iss >> type;
            std::getline(iss, data);
            this->push_back(FigureFactory::factory_instance().make_figure(type, data));
        }
        return *this;
    }

    FigureVec &stable_sort() {
        std::stable_sort(this->begin(), this->end(),
                         [](const auto &a, const auto &b) { return a->get_square() < b->get_square(); });
        return *this;
    }

    void print() {
        for (const auto &figure: *this)
            std::cout << figure->to_string() << std::endl;
    }
};


int main() {
    FigureVec().read().stable_sort().print();
}

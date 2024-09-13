#include <string>
#include <cmath>
#include <sstream>
#include <iomanip>


namespace numbers {
    class complex {
        double x = .0, y = .0;

    public:
        complex(double re = .0, double im = .0) : x(re), y(im) {}

        explicit complex(const std::string &s) : x(stod(s.substr(1, s.find(',') + 1))),
                                                 y(stod(s.substr(s.find(',') + 1))) {}

        double re() const { return x; }

        double im() const { return y; }

        double abs2() const { return x * x + y * y; }

        double abs() const { return std::sqrt(this->abs2()); }

        std::string to_string() const {
            std::stringstream ss;
            ss << std::setprecision(10) << "(" << x << "," << y << ")";
            return ss.str();
        }

        complex &operator+=(const complex &z) {
            x += z.x;
            y += z.y;
            return *this;
        }

        friend complex operator+(const complex &a, const complex &b) {
            complex tmp = a;
            return tmp += b;
        }

        complex operator-=(const complex &z) {
            x -= z.x;
            y -= z.y;
            return *this;
        }

        friend complex operator-(const complex &a, const complex &b) {
            complex tmp = a;
            return tmp -= b;
        }

        complex &operator*=(const complex &z) {
            double new_y = x * z.y + y * z.x;
            x = x * z.x - y * z.y;
            y = new_y;
            return *this;
        }

        friend complex operator*(const complex &a, const complex &b) {
            complex tmp = a;
            return tmp *= b;
        }

        complex &operator/=(const complex &z) {
            double new_y = (z.x * y - x * z.y) / z.abs2();
            x = (x * z.x + y * z.y) / z.abs2();
            y = new_y;
            return *this;
        }

        friend complex operator/(const complex &a, const complex &b) {
            complex tmp = a;
            return tmp /= b;
        }


    };

    complex operator~(const complex &a) { return {+a.re(), -a.im()}; }

    complex operator-(const complex &a) { return {-a.re(), -a.im()}; }
}

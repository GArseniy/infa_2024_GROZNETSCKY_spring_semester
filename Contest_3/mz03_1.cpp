#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

namespace numbers{
    class complex {
        double real, image;

    public:
        complex(double x = 0.0, double y = 0.0): real(x), image(y) {}
        
        explicit complex(const std::string & s) {
            size_t com = s.find(',');

            real = stod(s.substr(1, com + 1));
            image = stod(s.substr(com + 1));
        }

        double re() const {
            return real;
        }

        double im() const {
            return image;
        }

        double abs2() const {
            return real * real + image * image;
        }

        double abs() const {
            return sqrt(this->abs2());
        }

        std::string to_string() const{
            std::stringstream s;
            std::string str;

            s << '(';
            s << std::setprecision(10) << real;
            s << ',';
            s << std::setprecision(10) << image;
            s << ')';

            
            return s.str();
        }

        complex& operator+=(const complex& other) {
            real += other.real;
            image += other.image;

            return *this;
        }

        complex& operator-=(const complex& other) {
            real -= other.real;
            image -= other.image;

            return *this;
        }

        complex& operator*=(const complex& other) {
            
            complex tmp = *this;
            real = tmp.real * other.real - tmp.image * other.image;
            image = tmp.real * other.image + tmp.image * other.real;

            return *this;
        }

        complex& operator/=(const complex& other) {
            
            complex tmp = *this;
            real = (tmp.real * other.real + tmp.image * other.image) / other.abs2();
            image = (tmp.image * other.real - tmp.real * other.image) / other.abs2();

            return *this;
        }

        friend complex operator+(const complex& fir, const complex& sec) {
            complex tmp;
            tmp += fir;
            tmp += sec;

            return tmp;
        }

        friend complex operator-(const complex& fir, const complex& sec) {
            complex tmp;
            tmp += fir;
            tmp -= sec;

            return tmp;
        
        }
        
        friend complex operator*(const complex& fir, const complex& sec) {
            complex tmp;
            tmp += fir;
            tmp *= sec;

            return tmp;
        
        }
        
        friend complex operator/(const complex& fir, const complex& sec) {
            complex tmp;
            tmp += fir;
            tmp /= sec;

            return tmp;
        }

        complex operator~() const {
            
            return complex(real, -image);
        }

        complex operator-() const {
            return complex(-real, -image);
        }

    };
};

// int main() {
//     using namespace numbers;
    
//     complex a, b(1), c(2, 3);
//     const complex d, e(4), f(5, 6);

//     complex str("(-1,3)");
//     const complex cstr("-3, 1");

//     a += b;
//     a *= b;
//     a /= b;
//     a -= b;

//     c += d;
//     c -= d;
//     c *= d;
//     c /= d;

//     // d += f;

//     std::cout << f.to_string();

// }
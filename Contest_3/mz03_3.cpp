#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

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

namespace numbers
{
    class complex_stack {
        complex* stack;
        unsigned used;
        unsigned alloc;
    public:
        complex_stack(unsigned a = 100, unsigned u = 0): used(u), alloc(a) {
            stack = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));
        }

        complex_stack(const complex_stack& Stack): used(Stack.used), alloc(Stack.alloc) {
            stack = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));

            for (unsigned i = 0; i < Stack.used; i++) {
                stack[i] = Stack.stack[i];
            }
        }

        complex_stack operator=(const complex_stack& Stack) {
            complex_stack tmp(Stack);
            
            complex* time = stack;
            stack = tmp.stack;
            tmp.stack = time;

            used = tmp.used;
            alloc = tmp.alloc;

            return *this;
        }

        ~complex_stack() {
            for (unsigned i = 0; i < used; i++) {
                (stack + i)->~complex();
            }

            ::operator delete(stack);
        }

        unsigned get_u() const {
            return used;
        }

        void push(const complex& value) {
            if (used == alloc) {
                alloc <<= 1;
                complex* tmp = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));
                for (unsigned i = 0; i < used; i++) {
                    tmp[i] = stack[i];
                    stack[i].~complex();
                }

                ::operator delete(stack);
                stack = tmp;
            }

            stack[used++] = value;
        }

        void pop() {
            if (used) {
                used--;
                stack[used].~complex();
            }
        }

        size_t size() const {
            return used;
        }

        complex operator[](unsigned i) const {
            return stack[i];
        }

        friend complex_stack operator<<(const complex_stack& Stack, const complex& item) {
            complex_stack tmp(Stack);
            tmp.push(item);
        
            return tmp;
        }

        complex operator+() const {
            if (!used) {
                exit(1);
            }

            complex tmp = stack[used - 1];
            
            return tmp;
        }

        complex_stack operator~() const {
            complex_stack tmp(*this);
            tmp.pop();

            return tmp;

        }
    };
};

// /*
// В пространстве имен numbers реализуйте функцию eval с прототипом:

// complex eval(const std::vector<std::string> &args, const complex &z);
// Функции подается на вход польская инверсная запись выражения над комплексными числами с одной переменной и значение переменной. В качестве результата функция возвращает вычисленное значение.

// Каждый элемент польской записи находится в отдельном элементе вектора.

// Возможные ошибки при вычислении игнорируйте.

// Вы должны сдать только функцию eval.

// В польской записи допускаются следующие элементы:

// Запись комплексного числа в виде (RE,IM) (см. предыдущие задачи).
// Обозначение переменной "z" (строчная латинская буква).
// Знаки бинарных операций +, -, *, /.
// Знак унарной операции !, которая заносит в стек элемент, находящийся на верхушке стека.
// Знак унарной операции ;, которая удаляет элемент с верхушки стека.
// Знак унарной операции ~, которая вычисляет комплексно-сопряженное число.
// Знак унарной операции #, которая меняет знак у числа.
// Обратите внимание, что польская запись z1 z2 - обозначает (z1 - z2), а не (z2 - z1)!

// Каждая строка в массиве строк содержит ровно один элемент польской записи. Пробельные символы отсутствуют.

// Реализуйте отображение из операций в действия с помощью отображения (std::map) анонимных функций.
// */

namespace numbers {
    complex eval(const std::vector<std::string>& args, const complex& z) {
        std::vector<complex> Stack;
        for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); it++) {
            if ((*it)[0] == '(') {
                complex value(*it);
                Stack.push_back(value);                
            } else if (*it == "z") {
                Stack.push_back(z);
            } else if (*it == "+") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                a += b;
                Stack.push_back(a);
            } else if (*it == "-") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                b -= a;
                Stack.push_back(b);
            } else if (*it == "*") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                a *= b;
                Stack.push_back(a);
            } else if (*it == "/") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                b /= a;
                Stack.push_back(b);
            } else if (*it == "!") {
                complex a = Stack.back();
                Stack.push_back(a);
            } else if (*it == ";") {
                Stack.pop_back();
            } else if (*it == "~") {
                complex a = Stack.back();
                Stack.pop_back();
                Stack.push_back(~a);
            } else if (*it == "#") {
                complex a = Stack.back();
                Stack.pop_back();
                Stack.push_back(-a);
            }
        }

        return Stack.back();
    }
};

int main() {
    using namespace numbers;
    
    complex a, b(0), c(5.00123,-1.32434);
    std::string str = "(1.0,-5)";
    complex d(str);

    complex_stack g1, g2(g1), g3;
    g1 = g1 << d;
    g1 = g1 << d;
    g1 = g1 << d;
    g1 = g1 << d;
    g3 = g1;
    g1 = ~g1;

    std::vector<std::string> args;

    // (-12, 13) z ! ~ + - #
    args.push_back("(-12, 13)");
    args.push_back("z");
    args.push_back("!");
    args.push_back("~");
    args.push_back("+");
    args.push_back("-");
    args.push_back("#");

    complex x = eval(args, c);
    std::cout << x.to_string() << std::endl;

    return 0;
}
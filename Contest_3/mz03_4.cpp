#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

/*
Программе в аргументах командной строки передаются:

Комплексное число C.
Вещественное число R.
Целое число N.
Остальные аргументы - запись функции одного комплексного аргумента в польской записи.
На стандартный поток вывода напечатайте комплексное число I - результат вычисления криволинейного интеграла по замкнутому контуру - 
окружности с центром в точке C и радиусом R.

Для вычисления используйте метод прямоугольников. Для этого окружность делится на N частей.

В заголовочном файле cmc_complex.h находится реализация класса numbers::complex, 
в заголовочном файле cmc_complex_stack.h находится реализация класса numbers::complex_stack, 
в заголовочном файле cmc_complex_eval.h находится реализация функции eval.


*/

int main(int argc, char** argv) {
    using namespace numbers;
    
    if (argc < 4) {
        return -1;
    }

    complex result(0, 0);
    complex c(argv[1]);
    
    double r = strtod(argv[2], nullptr);
    complex rad(0, r);

    long n = strtol(argv[3], nullptr, 10);

    std::vector<std::string> expression;

    for (int i = 4; i < argc; i++) {
        expression.push_back(argv[i]);
    }

    for (long i = 0; i < n; i++) {
        double t = M_PI * (2 * i + 1) / n;
        complex t_val(cos(t), sin(t));

        complex dot(c.re() + r * t_val.re(), c.im() + r * t_val.im());

        result += eval(expression, dot) * rad * t_val;
    }

    result *= 2 * M_PI / n;

    std::cout << result.to_string() << std::endl;

}
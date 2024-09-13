#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double sum_x = 0;
    double sum_x_square = 0;
    int n = 0;

    double x;
    while (std::cin >> x) {
        sum_x += x;
        sum_x_square += x * x;
        ++n;
    }
    double expect_x = sum_x / n;
    double variance = sqrt(sum_x_square / n - pow(expect_x, 2));
    std::cout << std::setprecision(10) << expect_x << '\n' << variance << '\n';

    return 0;
}

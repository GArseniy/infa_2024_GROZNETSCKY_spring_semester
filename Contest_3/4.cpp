#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
#include <string>
#include <cmath>
#include <sstream>


int main(int argc, char *argv[]) {
    numbers::complex c = numbers::complex(argv[1]);
    double r = std::stod(argv[2]);
    long n = std::stoi(argv[3]);

    std::vector<std::string> function;
    for (int i = 4; i < argc; i++) {
        function.emplace_back(argv[i]);
    }

    numbers::complex result;
    for (long i = 0; i < n; ++i) {
        double t = M_PI * double(2 * i + 1) / double(n);
        numbers::complex angle = numbers::complex(r * cos(t), r * sin(t));
        result += eval(function, c + angle) * angle;
    }
    result *= 2 * M_PI / double(n);

    std::cout << result.to_string() << std::endl;
}

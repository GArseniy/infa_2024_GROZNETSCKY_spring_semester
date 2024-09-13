#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>


constexpr double PER_CENT = 0.1;
constexpr int PRECISION = 10;


struct Average {
    double sum = 0;
    int cnt = 0;

    void operator()(double num) { ++cnt, sum += num; }

    double get_mean() const { return sum / cnt; }
};


int main() {
    double num;
    std::vector<double> data;
    while (std::cin >> num) data.push_back(num);

    long start = long(double(data.size()) * PER_CENT);
    long end = long(data.size()) - start;

    std::sort(data.begin() + start, data.begin() + end);

    long dist = long(double(end - start) * PER_CENT);

    start += dist;
    end -= dist;

    std::cout << std::fixed << std::setprecision(PRECISION)
              << std::for_each(data.begin() + start, data.begin() + end, Average()).get_mean() << std::endl;
}

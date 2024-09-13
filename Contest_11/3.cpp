#include <functional>
#include <iostream>


void calc_binom(int m, int k, std::function<void(u_int64_t)> cb) {
    if (k < 0 || k > m) {
        cb(0);
        return;
    }
    if (k == 0 || k == m) {
        cb(1);
        return;
    }

    calc_binom(m - 1, k - 1, [cb, m, k](u_int64_t x) { cb((m * x) / k); });
    calc_binom(m - 1, k, [cb](u_int64_t x) { cb(x); });
}


int main() {
    calc_binom(5, 2, [](u_int64_t z) { std::cout << z << std::endl; });
}
#include <iostream>

struct S {
    int sum = 0;
    bool is_print = true;
    bool is_empty = true;

    ~S() { if (not is_print and not is_empty) std::cout << sum << std::endl; }

    operator bool() {
        int x;
        return (not(std::cin >> x)) ? (is_print = false) : (sum += x, is_empty = false, is_print = true);
    }
};

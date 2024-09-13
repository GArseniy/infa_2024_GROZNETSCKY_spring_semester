#include <iostream>

class A {
    int value;
public:
    A() {
        std::cin >> value;
    }

    A(A const &a) = default;

    A(A &&a) noexcept {
        int c;
        std::cin >> c;
        value = a.value + c;
    }

    ~A() {
        std::cout << value << '\n';
    }
};

int main() {
    A a, b(a);
}
#include <iostream>
#include <cctype>

int main() {
    bool is_zero = false;
    bool is_number = false;

    int c;
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            if (c == '0') {
                if (not is_number) {
                    is_zero = true;
                    continue;
                }
            } else {
                is_number = true;
                is_zero = false;
            }
        } else {
            if (is_zero) {
                std::cout << '0';
                is_zero = false;
            }
            is_number = false;
        }
        std::cout << char(c);
    }

    if (is_zero) {
        std::cout << '0';
    }

    return 0;
}
#include <iostream>
#include <iomanip>
#include <cmath>

enum {
    BYTE_COUNT = 4,
    LINE_SIZE = 16,
    SHIFT_0 = 24,
    SHIFT_1 = 16,
    SHIFT_2 = 8,
};

int main() {
    int line_number;
    unsigned value;
    unsigned blocks[BYTE_COUNT];

    while (std::cin >> std::hex >> line_number) {
        for (int i = 0; i < LINE_SIZE && std::cin >> std::hex >> blocks[i % BYTE_COUNT]; i++) {
            if (i % BYTE_COUNT == BYTE_COUNT - 1) {
                value = (blocks[0] << SHIFT_0) + (blocks[1] << SHIFT_1) + (blocks[2] << SHIFT_2) + blocks[3];
                std::cout << value << std::endl;
            }
        }
    }

    return 0;
}
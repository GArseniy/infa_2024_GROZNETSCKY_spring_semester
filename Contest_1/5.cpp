#include <iostream>


enum {
    CNT_NUMBER = 4,
    CNT_BYTE = 4,
    SHIFT = 8
};


int main() {
    std::cin >> std::hex;
    bool is_end = false;

    for (u_int32_t line; std::cin >> line;) {
        for (u_int32_t value = 0, i = 0; i < CNT_NUMBER; ++i) {
            for (u_int32_t block, j = 0; j < CNT_BYTE; ++j) {
                if (not(std::cin >> block)) {
                    is_end = true;
                }
                value <<= SHIFT;
                value |= block;
            }
            if (not is_end) {
                std::cout << value << std::endl;
            }
        }
    }
}

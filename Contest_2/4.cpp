#include <iostream>


enum {
    NON_CHAR_CODE = -2,
    MAX_LEN = 4,
    EMPTY = 0
};


int main() {
    for (int c, prev_c = NON_CHAR_CODE, len = EMPTY; (c = std::cin.get()) >= EOF; ++len) {
        if (prev_c == EOF) break;

        if (prev_c == c) continue;

        if (len <= MAX_LEN and prev_c != '#')
            for (int i = 0; i < len; ++i)
                std::cout << char(prev_c);
        else
            std::cout << '#' << char(prev_c) << std::hex << len << '#';

        prev_c = c;
        len = EMPTY;
    }
}

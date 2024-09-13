/*
        A -> aAd | B
        B -> bBc | epsilon
*/


#include <iostream>


void B(size_t);

void A(size_t l, size_t deep = 0) {
    if (l == 2) {
        std::cout << "bc";
        return;
    }

    if (!deep)
        for (size_t i = 0; i < l / 2 - 1; ++i)
            std::cout << 'a';

    A(l - 2, deep + 1);

    for (size_t i = 0; i <= deep; ++i)
        std::cout << 'd';

    std::cout << std::endl;

    for (size_t i = 0; i < deep; ++i)
        std::cout << 'a';

    if (deep) B(l);
}


void B(size_t l) {
    if (l == 2) {
        std::cout << "bc";
        return;
    }

    std::cout << 'b';
    B(l - 2);
    std::cout << 'c';
}

int main() {
    size_t l;
    std::cin >> l;
    if (l >= 4 && !(l % 2)) A(l);
}

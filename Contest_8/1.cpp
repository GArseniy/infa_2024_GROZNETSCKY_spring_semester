#include <iostream>
#include <string>


class ReversePrint {
    std::string str;
public:
    ReversePrint() { if (not(std::cin >> str)) throw 0; }

    ~ReversePrint() { std::cout << str << std::endl; }
};


int main() {
    try {
        ReversePrint printer;
        return main();
    } catch (int) {}
}

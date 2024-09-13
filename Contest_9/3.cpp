#include <iostream>

int main() {
    std::string input;
    while (std::cin >> input)
        std::cout << [i = 0, p = 0, q = 0](const std::string &s) mutable {
            for (; s[i] == 'a'; ++i, ++p);
            for (; s[i] == '0'; ++i, ++q);
            if (!p or !q) return false;

            for (; s[i] == 'b'; ++i, --p);
            for (; s[i] == '1'; ++i, --q);
            if (p or q) return false;

            return size_t(i) == s.size();
        }(input) << std::endl;
}

#include <iostream>
#include <string>


int main() {
    std::string input;
    while (std::cin >> input)
        std::cout << [i = 0](const std::string &s) mutable {
            for (; s[i] == '3' || s[i] == '4'; ++i);
            for (; s[i] == '1' || s[i] == '2'; ++i);

            return size_t(i) == s.size();
        }(input) << std::endl;
}

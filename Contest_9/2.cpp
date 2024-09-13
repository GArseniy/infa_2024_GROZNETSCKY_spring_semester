#include <iostream>
#include <string>


bool is_valid(const std::string &str) {
    int len = str.length();
    int i = -1;

    while (--len and str[len] == '0');

    if (len == str.length() or len-- == 0) return false;

    while (++i < len and str[i] == '1');

    if (i == len) return true;
    if (len % i) return false;
    if (str[i - 1] != '1') return false;

    for (int n = 0; i != len and str[i++] == str[n++];);

    return i == len;
}


int main() {
    std::string input;
    while (std::cin >> input)
        std::cout << is_valid(input) << std::endl;
}

#include <iostream>
#include <vector>
#include <algorithm>


bool comparator(uint a, uint b) {
    uint cnt_a = __builtin_popcount(a);
    uint cnt_b = __builtin_popcount(b);
    return cnt_a < cnt_b;
}


int main() {
    std::vector<uint> numbers;
    uint num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }

    std::stable_sort(numbers.begin(), numbers.end(), comparator);
    for (uint n: numbers) {
        std::cout << n << std::endl;
    }
}

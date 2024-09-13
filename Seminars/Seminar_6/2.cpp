#include <iostream>
#include <list>
#include <vector>


enum {
    N = 5
};


template<class T>
typename T::value_type sum(T &s) {
    typename T::value_type sum = {};
    auto it = s.cend();
    for (int i = 0; i < N; ++i) {
        it--;
        sum += *it;
    }
    return sum;
}


int main() {
    std::list<int> st = {9, 10};
    std::cout << sum<std::list<int>>(st) << std::endl;

    std::vector<long> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << sum(v) << std::endl;
}










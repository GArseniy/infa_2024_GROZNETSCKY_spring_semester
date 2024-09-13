#include <vector>
#include <iostream>


template<class T>
T abs(const T &a) {
    return (a >= 0) ? a : -a;
}

int f() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6};

    auto p = v.rbegin();
    while (p != v.rend())
        std::cout << *p++;


    std::cout << std::endl;

    auto q = v.end();
    while (q != v.begin())
        std::cout << *--q;

}

int main() {
    std::vector<char> v = {0, 1, 2, 3, 4, 5};

    auto p = v.begin();
    while (p != v.end()) {
        p = v.insert(p, *p);
        p++;
        p++;
    }


    auto q = v.begin();
    while (q != v.end())
        std::cout << *q++;
}
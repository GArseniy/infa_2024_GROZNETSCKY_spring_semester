#include <iostream>
#include <list>
#include <vector>

template<class T>
void rever(T b, T e) {
    if (b == e) { return; }
    e--;
    while (b != e) {
        typename T::value_type tmp{};
        tmp = *b;
        *b = *e;
        *e = tmp;
        if (--e == b++) { return; }
    }
}

int main() {
    std::list<int> st = {1, 3, 10, 15};
    std::vector<long> v = {1, 3, 10, 15};

    rever(st.begin(), st.end());
    rever(v.begin(), v.end());
}

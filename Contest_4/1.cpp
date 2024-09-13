#include <iostream>
#include <vector>


void process(const std::vector<u_int64_t> &v, std::vector<u_int64_t> &w, int x) {
    auto p = v.begin();
    auto q = w.rbegin();

    while (p < v.end() and q != w.rend()) {
        *q++ += *p;
        p += x;
    }
}



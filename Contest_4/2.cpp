#include <vector>
#include <iostream>


void process(std::vector<int64_t> &v, int64_t x) {
    auto p = v.rbegin();

    while (p != v.rend()) {
        if (*p >= x) {
            int64_t shift = std::distance(v.rbegin(), p);
            v.push_back(*p);
            p = v.rbegin() + shift + 1;
        }
        p++;
    }
}

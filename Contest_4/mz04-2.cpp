#include <vector>
#include <iostream>

void process(std::vector<long> &v, long limit) {
    if (v.size() == 0) {
        return;
    }
    std::vector<long>::iterator p = v.end() - 1;
    int i = 0;
    while (p != v .begin() - 1) {
        if (*p >= limit) {
            v.push_back(*p);
            i += 2;
        } else {
            i++;
        }
        p = v.end() - 1 - i;
    }
}
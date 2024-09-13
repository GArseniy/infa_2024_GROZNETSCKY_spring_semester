#include <iostream>
#include <vector>

void process(const std::vector<unsigned long>& v1, std::vector<unsigned long>& v2, int step) {
    std::vector<unsigned long>::const_iterator p1 = v1.begin();
    std::vector<unsigned long>::iterator p2 = v2.end();
    std::vector<unsigned long>::iterator p3 = v2.begin();
    p2--;
    p3--;
    while (p1 < v1.end() && p2 != p3) {
        *p2 += *p1;
        p2--;
        p1 += step;
    }
}

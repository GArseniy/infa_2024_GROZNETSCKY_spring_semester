#include <vector>
#include <algorithm>


void process(const std::vector<int> &v1, std::vector<int> &v2) {
    std::vector<int> unique_v1 = v1;
    std::sort(unique_v1.begin(), unique_v1.end());
    unique_v1.erase(std::unique(unique_v1.begin(), unique_v1.end()), unique_v1.end());

    for (auto it = unique_v1.rbegin(); it != unique_v1.rend(); ++it)
        if (*it >= 0 && u_int32_t(*it) < v2.size())
            v2.erase(v2.begin() + *it);
}

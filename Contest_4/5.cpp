#include <iostream>
#include <list>


int main() {
    std::list<int> list;
    int input;
    while (std::cin >> input and input)
        list.push_back(input);

    int x, y;
    while (std::cin >> x)
        if (x > 0) {
            std::cin >> y;
            auto it = list.begin();
            x = (x > int(list.size())) ? int(list.size()) : x - 1;
            advance(it, x);
            list.insert(it, y);
        } else {
            if (-x > int(list.size())) continue;
            auto it = list.begin();
            advance(it, -x - 1);
            list.erase(it);
        }

    for (int &it: list)
        std::cout << it << std::endl;
}

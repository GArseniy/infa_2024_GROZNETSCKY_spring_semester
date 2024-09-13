template<typename Container>
auto process(const Container &c) {
    enum {
        MAX = 5
    };

    auto sum = typename Container::value_type();
    auto it = c.rbegin();

    for (int i = 0; i < MAX; i += 2) {
        if (it == c.rend()) break;
        sum += *it;
        if (++it == c.rend() or ++it == c.rend()) break;
    }


    return sum;
}
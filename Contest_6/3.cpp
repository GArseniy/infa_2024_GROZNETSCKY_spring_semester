#include <vector>


template<typename Iterator, typename Function>
void myapply(Iterator begin, Iterator end, Function f) {
    for (auto it = begin; it != end; ++it)
        f(*it);
}


template<typename Iterator, typename Predicate>
std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>>
myfilter2(Iterator begin, Iterator end, Predicate pred) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<Iterator>::value_type>> result;
    for (auto it = begin; it != end; ++it)
        if (pred(*it))
            result.push_back(std::ref(*it));

    return result;
}

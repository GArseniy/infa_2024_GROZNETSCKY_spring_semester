#include <vector>


template<typename Iterator, typename Compare = std::less<typename Iterator::value_type>>
void selection_sort(Iterator begin, Iterator end, Compare comp = Compare()) {
    for (auto it = begin; it != end; ++it) {
        auto min_element_it = it;
        for (auto it2 = std::next(it); it2 != end; ++it2)
            if (comp(*it2, *min_element_it))
                min_element_it = it2;

        std::iter_swap(it, min_element_it);
    }
}

template<typename Container, typename Predicate>
Container myfilter(const Container &input, Predicate pred) {
    Container output;
    for (const auto &element: input) if (pred(element)) output.insert(output.end(), element);
    return output;
}
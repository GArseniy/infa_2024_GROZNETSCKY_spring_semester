#include <iostream>
#include <vector>
#include <algorithm>

// Шаблонная функция, принимающая два итератора, предикат и функцию преобразования
template <typename InputIterator, typename OutputIterator, typename Predicate, typename Function>
void process(InputIterator begin, InputIterator end, OutputIterator out, Predicate pred, Function func) {
    while (begin != end) {
        if (pred(*begin)) {
            *out = func(*begin);
            ++out;
        }
        ++begin;
    }
}

int main() {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> output(input.size());

    // Пример использования функции с предикатом и функцией преобразования
    process(input.begin(), input.end(), output.begin(),
            [](int x) { return x % 2 == 0; },  // Предикат - четные числа
            [](int x) { return x * 2; });      // Функция - умножение на 2

    std::cout << "Исходные элементы: ";
    for (const auto& elem : input) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Преобразованные элементы: ";
    for (const auto& elem : output) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}

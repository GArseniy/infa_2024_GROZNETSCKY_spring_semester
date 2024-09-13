#include <algorithm>
#include <iostream>
#include <format>
#include <vector>
#include <map>


class Date {
    int y, m, d;
public:
    Date(int y, int m, int d) : y(y), m(m), d(d) {}

    friend std::ostream &operator<<(std::ostream &os, const Date &date) {
        return os << std::format("{:04d}/{:02d}/{:02d}", date.y, date.m, date.d);
    }

    bool operator==(const Date &date) const { return y == date.y and m == date.m and d == date.d; }

    bool operator<(const Date &date) const {
        if (y != date.y) return y < date.y;
        if (m != date.m) return m < date.m;
        return d < date.d;
    }
};


char mark(const std::map<Date, int> &map, const Date &date) {
    return (map.find(date) != map.end()) ? char('0' + map.find(date)->second) : '.';
}


int main() {
    std::map<std::string, std::map<Date, int>> students;
    std::string name;
    int y, m, d, g;
    while ((std::cin >> name >> y) and (std::cin.ignore(), std::cin >> m) and (std::cin.ignore(), std::cin >> d >> g))
        students[name][Date(y, m, d)] = g;


    std::vector<Date> dates;
    for (auto &student: students)
        for (auto &mark: student.second)
            dates.push_back(mark.first);

    std::sort(dates.begin(), dates.end());
    dates.erase(std::unique(dates.begin(), dates.end()), dates.end());

    std::cout << '.' << '\t';
    for (auto &date: dates)
        std::cout << date << '\t';
    std::cout << std::endl;


    for (auto &student: students) {
        std::cout << student.first << '\t';
        for (auto &date: dates)
            std::cout << mark(student.second, date) << '\t';
        std::cout << std::endl;
    }
}

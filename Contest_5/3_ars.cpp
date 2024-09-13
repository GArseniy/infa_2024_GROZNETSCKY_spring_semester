#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <optional>

class Date {
public:
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    bool operator<(const Date &other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }

    bool operator==(const Date &other) const {
        return year == other.year && month == other.month && day == other.day;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date &date) {
        os << std::setfill('0') << std::setw(4) << date.year << "/" << std::setw(2) << date.month << "/" << std::setw(2) << date.day;
        return os;
    }

private:
    int year, month, day;
};

template <typename K, typename V>
std::optional<V> getValue(const std::map<K, V> &map, const K &key) {
    auto it = map.find(key);
    if (it != map.end()) {
        return it->second;
    }
    return std::nullopt;
}

int main() {
    std::map<std::string, std::map<Date, int>> grades;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream s(line);
        std::string name;
        int year, month, day, grade;

        s >> name >> year;
        s.ignore();
        s >> month;
        s.ignore();
        s >> day >> grade;

        Date date(year, month, day);
        grades[name][date] = grade;
    }

    std::vector<Date> Dates;
    for (const auto &student : grades) {
        for (const auto &entry : student.second) {
            Dates.push_back(entry.first);
        }
    }
    std::sort(Dates.begin(), Dates.end());
    Dates.erase(std::unique(Dates.begin(), Dates.end()), Dates.end());

    std::cout << ".\t";
    for (const auto &date : Dates) {
        std::cout << date << "\t";
    }
    std::cout << "\n";

    for (const auto &student : grades) {
        std::cout << student.first << "\t";
        for (const auto &date : Dates) {
            auto grade = getValue(student.second, date);
            if (grade) {
                std::cout << *grade << "\t";
            } else {
                std::cout << ".\t";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
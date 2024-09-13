#include <iostream>
#include <map>

enum {
    START = 1
};

int main() {
    std::map<std::string, std::pair<double, double>> students;

    std::string name;
    int mark;
    while (std::cin >> name >> mark)
        if (students.find(name) == students.end())
            students[name] = std::pair<int, int>(START, mark);
        else
            students[name].second = (students[name].first * students[name].second + mark) / ++students[name].first;

    for (const auto &student: students)
        std::cout << student.first << " " << student.second.second << std::endl;
}

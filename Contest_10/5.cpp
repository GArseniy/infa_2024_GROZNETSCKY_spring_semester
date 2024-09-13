#include <iostream>
#include <stack>
#include <string>


std::string convert(const std::string &input) {
    std::stack<std::string> operands;
    for (char s : input)
        if (isalpha(s)) {
            operands.push(std::string(1, s));
        } else {
            std::string op1 = operands.top();
            operands.pop();
            std::string op2 = operands.top();
            operands.pop();
            operands.push("(" + op2 + s + op1 + ")");
        }

    return operands.empty() ? "" : operands.top();
}


int main() {
    std::string s;
    std::cin >> s;
    std::cout << convert(s);
}

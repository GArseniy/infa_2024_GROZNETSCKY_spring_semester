#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace numbers {
    complex eval(const std::vector<std::string>& args, const complex& z) {
        std::vector<complex> Stack;
        for (std::vector<std::string>::const_iterator it = args.begin(); it != args.end(); it++) {
            if ((*it)[0] == '(') {
                complex value(*it);
                Stack.push_back(value);                
            } else if (*it == "z") {
                Stack.push_back(z);
            } else if (*it == "+") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                a += b;
                Stack.push_back(a);
            } else if (*it == "-") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                b -= a;
                Stack.push_back(b);
            } else if (*it == "*") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                a *= b;
                Stack.push_back(a);
            } else if (*it == "/") {
                complex a = Stack.back();
                Stack.pop_back();
                complex b = Stack.back();
                Stack.pop_back();

                b /= a;
                Stack.push_back(b);
            } else if (*it == "!") {
                complex a = Stack.back();
                Stack.push_back(a);
            } else if (*it == ";") {
                Stack.pop_back();
            } else if (*it == "~") {
                complex a = Stack.back();
                Stack.pop_back();
                Stack.push_back(~a);
            } else if (*it == "#") {
                complex a = Stack.back();
                Stack.pop_back();
                Stack.push_back(-a);
            }
        }

        return Stack.back();
    }
};

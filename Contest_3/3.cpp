#include <vector>
#include <functional>
#include <map>


namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack st;
        std::map<std::string, std::function<void()> > mp = {{"z", [&st, &z]() { st = st << z; }},
                                                            {"!", [&st]() { st = st << +st; }},
                                                            {";", [&st]() { st = ~st; }},
                                                            {"~", [&st]() { st = ~st << ~+st; }},
                                                            {"#", [&st]() { st = ~st << - +st; }},
                                                            {"+", [&st]() { st = ~~st << +~st + +st; }},
                                                            {"-", [&st]() { st = ~~st << +~st - +st; }},
                                                            {"*", [&st]() { st = ~~st << +~st * +st; }},
                                                            {"/", [&st]() { st = ~~st << +~st / +st; }}};
        for (const auto &s: args)
            if (s[0] != '(') mp[s]();
            else st = st << complex(s);

        return +st;
    }
}
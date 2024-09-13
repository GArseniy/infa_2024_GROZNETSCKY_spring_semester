compex eval(const vector <string> &args, const complex &z) {
    complex_stack st;
    map < string, function < void() > > mp
            {'z', [&st, &z]() { st = st << z; }},
            {';', [&st]() { st = ~st; }}; // To be continued
    for (const auto &s: args) {
        if (s[0] != '(') mp[s]();
        else st = st << compex(s);
    }
}
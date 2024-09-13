class Sum {
    int value = 0;
public:
    Sum(int a, int b) : value(a + b) {}

    Sum(Sum s, int c) : value(s.get() + c) {}

    Sum(int c, Sum s) : value(s.get() + c) {}

    int get() const {
        return value;
    }
};

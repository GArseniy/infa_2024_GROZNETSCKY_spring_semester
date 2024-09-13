class C {
public:
    C(int x = 0) {}

    C(const C &c1, const C &c2) {}

    friend C operator+(int x, const C &c) { return C(); }

    C operator++() { return C(); }

    int operator~() const { return 0; }

    int operator*(const C &c) { return 0; }

    C(const C *pc) {}
};

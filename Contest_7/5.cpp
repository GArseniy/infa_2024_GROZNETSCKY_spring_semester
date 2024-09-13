class Figure {
public:
    virtual bool equals(const Figure *other) const { return false; };

    virtual ~Figure() {}
};

class Rectangle : public Figure {
    int w, h;
public:
    Rectangle(int w, int h) : w(w), h(h) {}

    bool equals(const Figure *other) const {
        auto *rect = dynamic_cast<const Rectangle *>(other);
        if (not rect) return false;
        return (w == rect->w) and (h == rect->h);
    }
};

class Triangle : public Figure {
    int a, b, c;
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) {}

    bool equals(const Figure *other) const {
        auto *tri = dynamic_cast<const Triangle *>(other);
        if (not tri) return false;
        return (a == tri->a) and (b == tri->b) and (c == tri->c);
    }
};

int x = 0;


int f() { return x = 1; }


class A {
    int x;
public:
    A(int n = 2) { x = n; }

    int f() { return x = 3; }

    int f(int a, int b) { return x = a % b; }
};


class B : public A {
    int x;
public:
    int f(int a) { return x = a; }

    int f(int a, int b) { return x = a + b; }

    int g(A *a, B *b);
};


int B::g(A *pa, B *pb) {
    x = A::f(); //Fixed
    x = f(5);
    x = f(6, 6);
    x = f(5); //Fixed
    return -1;
}


int main() {
    B a;
    class C {
        B b;
        A a;
    public:
        C() : b(), a(b) {}
    };
    C c;
    x = a.A::f(); //Fixed
    x = a.f(7);
    return a.g(&a, &a);
}

// constructors: A(), B(), A(), B(), A(const) — это копирование с инициализацией, C()
// destructors: в обратном порядке
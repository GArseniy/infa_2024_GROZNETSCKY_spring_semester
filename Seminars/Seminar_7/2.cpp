// 3.1 a)


int x = 0;


void f(int a, int b) { x = a + b; }


class A {
    int x;
public:
    void f() { x = 2; }
};


class B : public A {
public:
    void f(int a) { ::x = a; }

    void g();
};


void B::g() {
    A::f(); //Fixed
    f(1);
    ::f(5, 1); //Fixed
    ::x = 2; //Fixed
}


B ret(B &x, B &y) {
    return x;
}


int main() {
    B b;
    f(5); //Error
    f('+', 6);
    b = ret(b, b);
    return 0;
}
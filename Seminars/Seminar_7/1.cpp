#include <iostream>


class A {
protected:
    int x;
public:
    void f() const { std::cout << x; }
};


class B : public A {
};


int main() {
    A a, *pa = &a;
    B b, *pb = &b;
    a = b;
    pa = pb;
    pa = (A *) pb; // for protected
    pb = (B *) pa; // only public
}
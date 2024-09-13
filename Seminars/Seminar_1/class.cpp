//huy.cpp — vkusno i tochka

#include <iostream>

class A {
    int a;
public:
    A(int x = 0) : a(x) {} // два конструктора: по умолчанию и преобразования

    void set_a(int x) {
        a = x; // this->a = x;
    }

    int get_a() {
        return a;
    }
};

int main() {

    A obj, object(5);
    obj.set_a(20);
    std::cout << obj.get_a() << std::endl;

    return 0;
}
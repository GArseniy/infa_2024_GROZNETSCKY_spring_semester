#include <iostream>
#include <cmath>


namespace numbers {
    class complex_stack {
        size_t capacity = START_CAP, s = 0;
        complex *data;

        enum {
            START_CAP = 100
        };

    public:
        explicit complex_stack(size_t cap = START_CAP) : capacity(cap), data(new complex[cap]) {}

        complex_stack(const complex_stack &c_s) : capacity(c_s.capacity), s(c_s.s), data(new complex[c_s.capacity]) {
            for (size_t i = 0; i < s; ++i) {
                data[i] = c_s.data[i];
            }
        }

        ~complex_stack() { delete[] data; }

        void pop() { s ? --s : 0; }

        void push(const complex &z) {
            if (capacity == s) {
                auto tmp = new complex[capacity <<= 1];
                for (size_t i = 0; i < s; ++i) {
                    tmp[i] = data[i];
                }
                delete[]data;
                data = tmp;
            }

            data[s++] = z;
        }

        size_t size() const { return s; }

        complex operator[](size_t i) const { return data[i]; }

        friend complex_stack operator<<(const complex_stack &c_s, const complex &z) {
            complex_stack tmp(c_s);
            tmp.push(z);
            return tmp;
        }

        complex operator+() const { return s ? data[s - 1] : 0; }

        complex_stack operator~() const {
            complex_stack tmp(*this);
            tmp.pop();
            return tmp;
        }

        complex_stack &operator=(const complex_stack &c_s) {
            complex_stack move_stack(c_s);

            s = move_stack.s;
            capacity = move_stack.capacity;

            auto tmp = data;
            data = move_stack.data;
            move_stack.data = tmp;

            return *this;
        }
    };
}

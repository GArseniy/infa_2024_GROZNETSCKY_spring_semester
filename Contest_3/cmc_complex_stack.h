#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

namespace numbers
{
    class complex_stack {
        complex* stack;
        unsigned used;
        unsigned alloc;
    public:
        complex_stack(unsigned a = 100, unsigned u = 0): used(u), alloc(a) {
            stack = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));
        }

        complex_stack(const complex_stack& Stack): used(Stack.used), alloc(Stack.alloc) {
            stack = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));

            for (unsigned i = 0; i < Stack.used; i++) {
                stack[i] = Stack.stack[i];
            }
        }

        complex_stack operator=(const complex_stack& Stack) {
            complex_stack tmp(Stack);
            
            complex* time = stack;
            stack = tmp.stack;
            tmp.stack = time;

            used = tmp.used;
            alloc = tmp.alloc;

            return *this;
        }

        ~complex_stack() {
            for (unsigned i = 0; i < used; i++) {
                (stack + i)->~complex();
            }

            ::operator delete(stack);
        }

        unsigned get_u() const {
            return used;
        }

        void push(const complex& value) {
            if (used == alloc) {
                alloc <<= 1;
                complex* tmp = static_cast<complex*>(::operator new(sizeof(*stack) * alloc));
                for (unsigned i = 0; i < used; i++) {
                    tmp[i] = stack[i];
                    stack[i].~complex();
                }

                ::operator delete(stack);
                stack = tmp;
            }

            stack[used++] = value;
        }

        void pop() {
            if (used) {
                used--;
                stack[used].~complex();
            }
        }

        size_t size() const {
            return used;
        }

        complex operator[](unsigned i) const {
            return stack[i];
        }

        friend complex_stack operator<<(const complex_stack& Stack, const complex& item) {
            complex_stack tmp(Stack);
            tmp.push(item);
        
            return tmp;
        }

        complex operator+() const {
            if (!used) {
                exit(1);
            }

            complex tmp = stack[used - 1];
            
            return tmp;
        }

        complex_stack operator~() const {
            complex_stack tmp(*this);
            tmp.pop();

            return tmp;

        }
    };
};

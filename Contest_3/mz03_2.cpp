#include <iostream>
#include <cmath>
#include "cmc_complex.h"


/*
В пространстве имен numbers реализуйте класс complex_stack, который будет реализовывать функциональность иммутабельного стека
комплексных чисел из предыдущей задачи.

Реализация не должна использовать стандартные контейнерные классы (vector, stack и т. п.).

Класс должен реализовывать:

конструктор по умолчанию.
конструкторы, деструкторы и операции, необходимые для корректного управления памятью.
метод size для получения числа элементов в стеке (возвращает size_t).
доступ к произвольному элементу стека только на чтение с помощью операции [].
бинарный оператор <<, у которого первый аргумент - complex_stack, а второй аргумент - complex,
    бинарный оператор возвращает новый стек, в который добавлен указанный элемент. Исходный стек не изменяется.
унарный оператор +, который возвращает элемент типа complex с вершины стека.
унарный оператор ~, который удаляет один элемент из стека и возвращает модифицированный стек, исходный стек при этом не изменяется.
На проверку сдавайте только класс complex_stack.

Возможные ошибки (извлечение из пустого стека, доступ за пределами стека) игнорируйте.

Дополнительно реализуйте:

Семантику переноса в конструкторе, присваивании и операциях << и ~
placement new для минимизации вызовов конструкторов при перевыделении памяти

*/


namespace numbers {
    class complex_stack {
        complex *stack;
        unsigned used;
        unsigned alloc;
    public:
        complex_stack(unsigned a = 100, unsigned u = 0) : used(u), alloc(a) {
            stack = static_cast<complex *>(::operator new(sizeof(*stack) * alloc));
        }

        complex_stack(const complex_stack &Stack) : used(Stack.used), alloc(Stack.alloc) {
            stack = static_cast<complex *>(::operator new(sizeof(*stack) * alloc));

            for (unsigned i = 0; i < Stack.used; i++) {
                stack[i] = Stack.stack[i];
            }
        }

        complex_stack operator=(const complex_stack &Stack) {
            complex_stack tmp(Stack);

            complex *time = stack;
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

        void push(const complex &value) {
            if (used == alloc) {
                alloc <<= 1;
                complex *tmp = static_cast<complex *>(::operator new(sizeof(*stack) * alloc));
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

        friend complex_stack operator<<(const complex_stack &Stack, const complex &item) {
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
}

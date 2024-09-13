#include <cstring>
#include <iostream>

class String {
public:
    char *str;
    int len;

    String(int l = 1) {
        len = l;
        str = new char[len + 1];
        str[len] = 0;
    }

    String(const char *s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        str[len] = 0;
    }

    String(const String &s) {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }

    ~String() {
        delete[] str;
    }

    char &operator[](int i) {
        return str[i];
    }

    String operator+(const String &s) {
        auto new_s = new String(len + s.len);
        strcpy(new_s->str, str);
        strcat(new_s->str, s.str);
        return *new_s;
    }
};

int main() {
    String s1("abcd"), s2("klm"), s3;
    s2[1] = 'A';
    s3 = s1 + s2;
    std::cout << s3.str;
    return 0;
}

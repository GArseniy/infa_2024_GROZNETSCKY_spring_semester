//cons
//copy
//cons
//des
//copy
//des
//des
//1
//des


#include <cstring>

class String {
    char *str;
    int len;
public:
    explicit String(int l = 1) {
        if (len <= 0) {
            l = 1;
        }

        len = l;
        str = new char[len];
        str[0] = 0;
    }

    explicit String(const char *s) {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    String(const String &s) {
        len = s.len;
        str = new char[len];
        strcpy(str, s.str);
    }

    ~String() {
        delete[]str;
    }
};


int main() {

}
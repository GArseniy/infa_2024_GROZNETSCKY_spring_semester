#include <string>
#include <utility>

class BinaryNumber {
    std::string bin_str;
public:
    BinaryNumber(std::string s) : bin_str(std::move(s)) {}

    operator std::string() const {
        return bin_str;
    }

    const BinaryNumber &operator++() {
        bool add = true;
        for (int i = bin_str.length(); i-- > 0;) {
            bin_str[i] = bin_str[i] == '1' ? '0' : (add = false, '1');
            if (not add) {
                break;
            }
        }
        if (add) {
            bin_str.insert(0, "1");
        }
        return *this;
    }
};

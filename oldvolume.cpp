#include <iostream>

class Volume {
public:
    static const int DEFAULT_VALUE = 0;
    static const int MINIMUM_VALUE = 0;
    static const int MAXIMUM_VALUE = 100;

    Volume(const bool shouldClamp = false) {
        clamping = shouldClamp;
        value = DEFAULT_VALUE;
    }

    Volume(int v, bool shouldClamp = false) {
        clamping = shouldClamp;
        setValue(v);
    }

    int getValue() const {
        return value;
    }

    bool isClamping() const {
        return clamping;
    }

    void setClamping(bool shouldClamp) {
        clamping = shouldClamp;
    }

    void setValue(const int v) {
        if (v >= MINIMUM_VALUE && v <= MAXIMUM_VALUE) {
            value = v;
        }
        else {
            if (clamping) {
                if (v < MINIMUM_VALUE) {
                    value = MINIMUM_VALUE;
                }
                else if (v > MAXIMUM_VALUE) {
                    value = MAXIMUM_VALUE;
                }
                else {
                    value = v;
                }
            }
            else {
                throw std::invalid_argument("value must be between 0 and 100");
            }
        }
    }

private:
    int value;
    bool clamping;
};

int main() {
    std::cout << "Volume min = " << Volume::MINIMUM_VALUE
        << " max = " << Volume::MAXIMUM_VALUE
        << " default = " << Volume::DEFAULT_VALUE
        << '\n';

    Volume v1(35);
    std::cout << "v1 = " << v1.getValue() << std::endl;

    Volume v2;
    std::cout << "v2 = " << v2.getValue() << std::endl;

    v2.setClamping(true);
    v2.setValue(5000);
    std::cout << "v2 now = " << v2.getValue() << std::endl;
}

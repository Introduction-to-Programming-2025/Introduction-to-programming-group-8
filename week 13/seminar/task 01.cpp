#include <iostream>

unsigned pow(unsigned base, unsigned power) {
    if (power == 0) {
        return 1;
    }

    if (power == 1) {
        return base;
    }

    if (power % 2) {
        return pow(base, power - 1) * base;
    }

    unsigned result = pow(base, power / 2);
    return result * result;
}

int main() {
    unsigned a, p;
    std::cin >> a >> p;

    std::cout << pow(a, p) << std::endl;

    return 0;
}

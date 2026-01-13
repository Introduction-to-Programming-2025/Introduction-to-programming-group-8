#include <iostream>

int staircase(int stairs) {
    if (stairs == 0) {
        return 1;
    }

    if (stairs < 0) {
        return 0;
    }

    return staircase(stairs - 1) + staircase(stairs - 2) + staircase(stairs - 3);
}

int main() {
    unsigned s, n;
    std::cin >> s;

    for (unsigned i = 0; i < s; ++i) {
        std::cin >> n;
        std::cout << staircase(n) << std::endl;
    }
    

    return 0;
}

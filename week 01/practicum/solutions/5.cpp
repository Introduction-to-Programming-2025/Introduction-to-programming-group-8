#include <iostream>

int main() {
    unsigned number = 0;

    std::cin >> number;

    std::cout << (1 - (number & 1)) << std::endl;

    return 0;
}

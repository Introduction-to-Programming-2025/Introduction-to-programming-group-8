#include <iostream>

int main() {
    const size_t MAX_SIZE = 16;
    size_t n, m;
    unsigned arrayA[MAX_SIZE], arrayB[MAX_SIZE];
    unsigned int numberA = 0, numberB = 0;

    std::cin >> n;
    while (n > 16) {
        std::cout << "N must be between 0 and 16" << std::endl;
        std::cin >> n;
    }

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arrayA[i];
        while (arrayA[i] > 9) {
            std::cout << "The digits must be between 0 and 9" << std::endl;
            std::cin >> arrayA[i];
        }
    }

    std::cin >> m;
    while (m > 16) {
        std::cout << "M must be between 0 and 16" << std::endl;
        std::cin >> m;
    }


    for (size_t i = 0; i < m; ++i) {
        std::cin >> arrayB[i];
        while (arrayB[i] > 9) {
            std::cout << "The digits must be between 0 and 9" << std::endl;
            std::cin >> arrayB[i];
        }
    }

    for (size_t i = 0; i < n; ++i) {
        numberA *= 10;
        numberA += arrayA[i];
    }

    for (size_t i = 0; i < m; ++i) {
        numberB *= 10;
        numberB += arrayB[i];
    }


    std::cout << numberA + numberB << std::endl;

    return 0;
}

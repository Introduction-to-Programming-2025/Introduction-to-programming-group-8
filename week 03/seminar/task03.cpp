#include <iostream>
// библиотека за sqrt
#include <cmath>

int main() {
    unsigned int number;

    std::cin >> number;

    unsigned int numberSqrt = sqrt(number);
    bool isPrime = true;

    for (unsigned int x = 2; x <= numberSqrt && isPrime; ++x) {
        // ако number се дели на x, резултатът ще е 0
        isPrime = number % x;
    }

    std::cout << std::boolalpha << isPrime << std::endl;

    return 0;
}

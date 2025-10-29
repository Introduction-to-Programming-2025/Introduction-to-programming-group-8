#include <iostream>

int main() {
    int number, mirroredNumber;

    std::cin >> number;

    if (number < 0) {
        number *= -1;
    }  // number = abs(number)

    mirroredNumber = 0;
    while(number > 0) {
        short digit = number % 10;
        number /= 10;

        mirroredNumber *= 10;
        mirroredNumber += digit;
    }

    bool oddPosition = true;
    while (mirroredNumber > 0) {
        short digit = mirroredNumber % 10;
        mirroredNumber /= 10;

        if (!oddPosition) {
            std::cout << digit << " ";
        }

        oddPosition = !oddPosition;
    }

    std::cout << std::endl;

    return 0;
}
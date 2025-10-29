#include <iostream>

int main() {
    // int побира ~10 цифри, в условието се изискват до 12
    unsigned long number; 

    std::cin >> number;

    // създаваме копие, за да не нарушаваме числото
    unsigned long numberCopy = number;
    unsigned long numberMirror = 0;

    while (numberCopy > 0) {
        short digit = numberCopy % 10;
        numberCopy /= 10;

        numberMirror *= 10;
        numberMirror += digit;
    }

    std::cout << std::boolalpha << (number == numberMirror) << std::endl;

    return 0;
}

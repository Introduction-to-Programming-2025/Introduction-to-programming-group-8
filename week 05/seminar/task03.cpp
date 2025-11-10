#include <iostream>

int main() {
    unsigned int number;

    bool digits[10] = {};

    std::cin >> number;

    unsigned int numberCopy = number;

    while (numberCopy > 0) {
        int digit = numberCopy % 10;
        numberCopy /= 10;

        digits[digit] = true;
    } 

    // for (size_t i = 0; i < 10; ++i) std::cout << digits[i] << " ";

    int changeWith = 9;
    while (digits[changeWith]) {
        --changeWith;
    }

    // std::cout << changeWith;

    int reversed = 0;

    while (number > 0) {
        int digit = number % 10;
        number /= 10;

        reversed *= 10;
        reversed += digit;
    }

    // std::cout << reversed << " " << number;

    int toChange = -1;
    while (reversed > 0) {
        int digit = reversed % 10;
        reversed /= 10;

        if ((toChange == -1 && digit < changeWith) || (toChange == digit)) {
            toChange = digit;
            digit = changeWith;
        }

        number *= 10;
        number += digit;
    }

    std::cout << number << std::endl;

    return 0;
}

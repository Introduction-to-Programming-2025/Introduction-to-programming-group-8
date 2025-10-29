#include <iostream>

int main() {
    size_t number; // unsigned int/long number

    std::cin >> number;

    for (size_t i = 0; i < number; i++) {
        if (i % 2) {
            for (size_t j = number; j > 0; j--) {
                std::cout << i * number + j << " ";
            }
        }
        else {
            for (size_t j = 1; j <= number; j++) {
                std::cout << i * number + j << " ";
            }
        }

        std::cout << std::endl;
    }


    return 0;
}

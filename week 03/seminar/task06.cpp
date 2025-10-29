#include <iostream>

int main() {
    int number;
    
    std::cin >> number;

    // предпочита се работа с положителни числа
    if (number < 0) {
        number *= -1;
    }

    bool found3 = false, favourite = false;
    while (number > 0 && !favourite) {
        short digit = number % 10;
        number /= 10;

        // отбелязва се срещане на 3
        if (digit == 3) {
            found3 = true;
        }

        // при срещане на 1, ако 3 е вече срещнато
        if (digit == 1 && found3) {
            favourite = true;
        }
    }

    std::cout << (favourite ? "yes" : "no") << std::endl;

    return 0;
}

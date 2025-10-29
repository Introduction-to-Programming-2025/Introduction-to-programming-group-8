#include <iostream>

int main() {
    double result = 0, number;
    char operation = '+';

    do {
        std::cin >> number;

        switch(operation) {
            case '+': result += number; break;
            case '-': result -= number; break;
            case '*': result *= number; break;
            case '/': result /= number; break;
        }

        std::cin >> operation;

    } while (operation != '=');

    std::cout << result << std::endl;

    return 0;
}

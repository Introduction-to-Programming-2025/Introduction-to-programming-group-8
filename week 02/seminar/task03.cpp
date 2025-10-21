#include <iostream>

int main() {
    int number1, number2, number3, number4, number5;

    std::cin >> number1 >> number2 >> number3 >> number4 >> number5;

    int result = number1 ^ number2;
    result = result ^ number3;
    result = result ^ number4;
    result = result ^ number5;

    std::cout << result << std::endl;

    return 0;
}
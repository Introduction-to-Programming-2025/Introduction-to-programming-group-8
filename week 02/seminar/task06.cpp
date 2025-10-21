#include <iostream>

int main() {
    unsigned short number1, number2, number3, number4, number5;

    std::cin >> number1 >> number2 >> number3 >> number4 >> number5;

    // сортиране на числата в нарастващ ред
    if (number1 > number2) 
        std::swap(number1, number2);
    if (number1 > number3)
        std::swap(number1, number3);
    if (number1 > number4)
        std::swap(number1, number4);
    if (number1 > number5)
        std::swap(number1, number5);
    
    if (number2 > number3)
        std::swap(number2, number3);
    if (number2 > number4)
        std::swap(number2, number4);
    if (number2 > number5)
        std::swap(number2, number5);

    if (number3 > number4)
        std::swap(number3, number4);
    if (number3 > number5)
        std::swap(number3, number5);

    if (number4 > number5)
        std::swap(number4, number5);

    if (number1 == number2 && number2 == number3 && 
        number3 == number4 && number4 == number5)
        std::cout << "Impossible" << std::endl;
    else if ((number1 == number2 && number2 == number3 && number3 == number4) ||
        (number2 == number3 && number3 == number4 && number4 == number5))
        std::cout << "Four of a Kind" << std::endl; 
    else if ((number1 == number2 &&  number3 == number4 && number4 == number5) ||
        (number1 == number2 &&  number2 == number3 && number4 == number5))
        std::cout << "Full House" << std::endl;
    else if ((number1 == number2 && number2 == number3) ||
        (number2 == number3 && number3 == number4) ||
        (number3 == number4 && number4 == number5))
        std::cout << "Three of a Kind" << std::endl;
    else if ((number1 == number2 && (number3 == number4 || number4 == number5)) ||
        (number2 == number3 && number4 == number5))
        std::cout << "Two Pairs" << std::endl;
    else if (number1 == number2 - 1 && number2 == number3 - 1 &&
        number3 == number4 - 1 && number4 == number5 - 1)
        std::cout << "Straight" << std::endl;
    else std::cout << "Nothing" << std::endl;

    return 0;
}

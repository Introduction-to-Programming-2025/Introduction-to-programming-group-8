#include <iostream>

int main() {
    int number = 0, digit = 0;
    
    std::cin >> number >> digit;

    std::cout << (-34 % 10);

    // Искаме да се отървем от минуса, защото -34 % 10 == -4
    int sign = (number >= 0) - (number < 0);
    number *= sign;

    int firstLetter = (number / 100) % 10;
    int secondLetter = (number / 10)  % 10;
    int thirdLetter =  number % 10;

    bool found = (digit == firstLetter) || (digit == secondLetter) || (digit == thirdLetter);
    
    std::cout << found << std::endl;
    
    return 0;
}

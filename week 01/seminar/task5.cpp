/*
Да се изведе сумата на всички числа от затворения интервал [A, B].
*/

#include <iostream>

int main() {
    int a, b;
    
    std::cin >> a >> b;

    std::cout << (b - a + 1) * (a + b) / 2 << std::endl;


    return 0;
}
#include <iostream>

// Това решение използва "алчен" алгоритъм. За да се убедим, че работи, трябва да се запознаем с 
// доказателства за коректност, които се учат по Дизайн и анализ на алгоритмни във 2ри курс.
int main() {
    unsigned times = 0;

    std::cin >> times;

    unsigned tensCount = times / 10;
    times %= 10;

    unsigned fivesCount = times / 5;
    
    unsigned onesCount = times % 5;

    unsigned total = tensCount * 7 + fivesCount * 4 + onesCount * 1;

    std::cout << "Packets of 10: "  << tensCount  << std::endl;
    std::cout << "Packets of 5: "   << fivesCount << std::endl;
    std::cout << "Packets of 1: " << onesCount  << std::endl;
    std::cout << "Min price: " << total << "lv" << std::endl;

    return 0;
}

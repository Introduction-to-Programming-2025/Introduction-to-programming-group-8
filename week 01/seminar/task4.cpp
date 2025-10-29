/*
Огледално на дадено цяло число number се нарича такова число, съставено от цифрите на number, 
но подредени в обратен ред. Да се напише програмен фрагмент, който въвежда цяло четирицифрено число 
и намира и извежда огледалното му число.
*/

#include <iostream>

int main () {
    int number;

    std::cin >> number;

    // цифра на единиците
    short digit1 = number % 10;
    number /= 10;

    // цифра на десетиците
    short digit10 = number % 10;
    number /= 10;

    // цифра на стотиците
    short digit100 = number % 10;
    number /= 10;
    
    // цифра на хилядните
    short digit1000 = number;

    int mirrorNumber = digit1 * 1000 + digit10 * 100 + digit100 * 10 + digit1000;

    std::cout << mirrorNumber << std::endl;

    return 0;
}
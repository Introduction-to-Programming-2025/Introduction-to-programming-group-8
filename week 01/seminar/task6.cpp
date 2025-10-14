/*
Да се напише потребителски интерфейс, който изисква от потребителя да въведе количество и цена за ябълки, 
портокали и банани. Накрая да се изведе сметката на потребителя: какъв брой от какво си е поръчал и колко ще му струва.
*/

#include <iostream>

int main() {
    unsigned int applesCount, bananaCount, orangesCount;
    double applesPrice, bananaPrice, orangesPrice;

    std::cout << "Apples: ";
    std::cin >> applesCount >> applesPrice;

    std::cout << "Oranges: ";
    std::cin >> orangesCount >> orangesPrice;

    std::cout << "Bananas: ";
    std::cin >> bananaCount >> bananaPrice;

    double applesTotal = applesCount * applesPrice;
    double orangesTotal = orangesCount * orangesPrice;
    double bananasTotal = bananaCount * bananaPrice;

    std::cout << "Your order is: apples for " << applesTotal << ", oranges for " << orangesTotal;
    std::cout << " and bananas for " << bananasTotal << ". Total: " << applesTotal + orangesTotal + bananasTotal << "." << std::endl;

    return 0;
}
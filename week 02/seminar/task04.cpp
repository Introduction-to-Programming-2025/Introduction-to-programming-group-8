#include <iostream>

int main() {
    int number;

    std::cin >> number;

    std::cout << std::boolalpha << (number && !(number & (number - 1))) << std::endl;

    return 0;
}
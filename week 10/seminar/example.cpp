#include <iostream>
#include <cstring>
#include "mystring.hpp"

int main() {
    char *str = new char[10], *str2 = new char[10];

    std::cin >> str >> str2;
    // std::cin.getline(str, 10);
    // std::cin.getline(str, 10, '~');

    std::cout << str << " " << str2 << std::endl;
    // std::cout << length(str) << " " << strlen(str) << std::endl;
    // std::cout << compare(str, str2) << " " << strcmp(str, str2) << std::endl;

    // concat(str, "jgjfjjkffff");
    // std::cout << str << std::endl;

    // std::cout << strcat(str, str2) << " " << str << std::endl;

    // copy(str, str2);
    strcpy(str, str2);
    std::cout << str << std::endl;



    delete[] str;
    delete[] str2;

    return 0;
}
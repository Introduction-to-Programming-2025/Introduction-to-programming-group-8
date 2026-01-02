#include <iostream>
#include "stringExtention.hpp"

int main() {
    char *str1 = new char[20], *str2 = new char[20];
    // str2 = "testtest";

    // nCopy(str1, str2, 5);

    // std::cout << str1 << std::endl;

    char** list = nullptr;
    size_t size = 0;

    str2 = "asdf abc fgh";
    split(str2, list, size);

    join(str1, list, size, '.');

    std::cout << str1 << std::endl;

    for (size_t i = 0; i < size; ++i) {
        delete[] list[i];
    }
    delete[] list;

    delete[] str1;
    delete[] str2;
    return 0;
}
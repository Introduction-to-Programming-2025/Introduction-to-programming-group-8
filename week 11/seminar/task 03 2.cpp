#include <iostream>
#include <cstring>
#include "stringExtention.hpp"

int main() {
    char str[1025], word1[129], word2[129];

    std::cin.getline(str, 1025);
    std::cin >> word1 >> word2;

    char **list = nullptr;
    size_t size;

    split(str, list, size);

    for(size_t i = 0; i < size; ++i) {
        if(!strcmp(list[i], word1)) {
            strcpy(list[i], word2);
        }
    }

    for(size_t i = 0; i < size; ++i) {
        std::cout << list[i] << std::endl;
    }

    char *result = new char[1025];
    join(result, list, size);

    std::cout << result << std::endl;

    for(size_t i = 0; i < size; ++i) {
        delete[] list[i];    
    }
    delete[] list;
    delete[] result;

    return 0;
}

#include <iostream>
#include <cstring>
#include "stringExtention.hpp"

int main() {
    const size_t STRSIZE = 128;
    size_t n;

    std::cin >> n;
    std::cin.ignore();

    char **names = new char*[n];
    char **namesSet = nullptr;
    size_t setSize = 0;

    for (size_t i = 0; i < n; ++i) {
        names[i] = new char[STRSIZE + 1];

        std::cin.getline(names[i], STRSIZE);
        addToSet(names[i], namesSet, setSize);
    } 

    for (size_t i = 0; i < setSize; ++i) {
        std::cout << namesSet[i] << std::endl;
    }

    size_t index;
    int maxCount = 0;

    for (size_t i = 0; i < setSize; ++i) {
        int count = 0;
        for (size_t j = 0; j < n; ++j) {
            if (!strcmp(namesSet[i], names[j])) {
                count ++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }

    /*
    for (size_t i = 0; i < n; ++i) {
        int count = 1;
        for (size_t j = i + 1; j < n; ++j) {
            if (!strcmp(names[i], names[j])) {
                count ++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            index = i;
        }
    }
    */

    std::cout << namesSet[index] << " " << maxCount << std::endl;

    for(size_t i = 0; i < setSize; ++i) {
        delete[] namesSet[i];
    }
    delete[] namesSet;

    for(size_t i = 0; i < n; ++i) {
        delete[] names[i];
    }
    delete[] names;

    return 0;
}

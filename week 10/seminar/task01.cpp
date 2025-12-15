#include <iostream>
#include "mystring.hpp"

int main() {
    const size_t STRSIZE = 128;

    size_t n; 
    std::cin >> n;

    char** array = new char*[n];

    for (size_t i = 0; i < n; ++i) {
        array[i] = new char[STRSIZE];

        std::cin >> array[i];
    }

    sort(array, n);

    // for (size_t i = 0; i < n; ++i) {
    //     std::cout << array[i] << std::endl;
    // }

    std::cout << array[n - 1] << std::endl;

    for (size_t i = 0; i < n; ++i) {
        delete[] array[i];
    }

    delete[] array;

    return 0;
}
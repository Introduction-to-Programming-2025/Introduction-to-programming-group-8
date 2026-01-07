#ifndef __ARRAY__
#define __ARRAY__
// #pragma once
#include <iostream>

void input(int array[], size_t& size) {
    std::cin >> size;

    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    } 
}

void output(int array[], const size_t& size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    } 
    std::cout << std::endl;
}

#endif // __ARRAY__
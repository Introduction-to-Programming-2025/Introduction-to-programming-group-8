#include <iostream>

void inputArray(int array[], size_t& size) {
    std::cin >> size;

    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
}

int main () {
    const size_t MAX_SIZE = 128;
    size_t n, m;
    int arrA[MAX_SIZE], arrB[MAX_SIZE];

    inputArray(arrA, n);
    inputArray(arrB, m);

    int count = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < m; ++j) {
            count += (*(arrA + i) == *(arrB + j));
        }
    }

    std::cout << count << std::endl;

    return 0;
}
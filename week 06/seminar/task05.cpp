#include <iostream>

void inputArray(int array[], size_t& size) {
    std::cin >> size;

    for (size_t i = 0; i < size; ++i) {
        std::cin >> *(array + i);
    }
}

void outputArray(int array[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << *(array + i) << " ";
    }

    std::cout << std::endl;
}

int main () {
    const size_t MAX_SIZE = 128;
    size_t n;
    int array[MAX_SIZE];

    inputArray(array, n);

    bool periodFound = false;

    for (size_t period = 1; period < n && !periodFound; ++period) {
        bool isValidPeriod = (n % period == 0);

        for (size_t i = 0; i < n - period && isValidPeriod; ++i) {
            isValidPeriod = *(array + i) == *(array + i + period);
        }

        if (isValidPeriod) {
            periodFound = true;
            outputArray(array, period);
        }
    }

    if (!periodFound) {
        std::cout << "Not period" << std::endl;
    }

    return 0;
}
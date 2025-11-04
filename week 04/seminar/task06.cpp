#include <iostream>

int main() {
    const size_t MAX_SIZE = 128;
    size_t n;
    int array[MAX_SIZE], sum;

    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    std::cin >> sum;

    bool canSum = false;

    for (size_t i = 0; i < n && !canSum; ++i) {
        int currentSum = 0;

        for (size_t j = i; j < n; ++j) {
            currentSum += array[j];

            if (currentSum == sum) {
                canSum = true;
            }
        }
    } 

    std::cout << (canSum ? "Yes" : "No") << std::endl;

    return 0;
}

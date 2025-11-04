#include <iostream>

int main() {
    const size_t MAX_SIZE = 128;
    int array[MAX_SIZE];
    size_t n;

    std::cin >> n;
    for  (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    size_t maxArrStart = 0, maxArrSize = 0;
    size_t currentArrStart = 0, currentArrSize = 1;
    
    for (size_t i = 1; i < n; ++i) {
        if (array[i] == array[currentArrStart]) {
            currentArrSize ++;
        }
        else {
            if (currentArrSize > maxArrSize) {
                maxArrSize = currentArrSize;
                maxArrStart = currentArrStart;
            }

            currentArrSize = 1;
            currentArrStart = i;
        }
    }

    if (currentArrSize > maxArrSize) {
        maxArrSize = currentArrSize;
        maxArrStart = currentArrStart;
    }

    std::cout << maxArrSize << " " << maxArrStart << " " << maxArrStart + maxArrSize - 1 << std::endl;

    return 0;
}

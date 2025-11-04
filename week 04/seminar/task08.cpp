#include <iostream>

int main() {
    const size_t MAX_SIZE = 1024;
    bool games[MAX_SIZE] = {};
    size_t n, maxEnd = 0;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        size_t start, end;
        std::cin >> start >> end;

        for (size_t j = start; j <= end; ++j) {
            games[j] = true;
        }

        if (end > maxEnd) maxEnd = end;
    }

    size_t maxStart = 0, maxSize = 0, currentStart = 0, currentSize = 1;

    for (size_t i = 1; i <= maxEnd; ++i) {
        if (games[i] == games[currentStart]) {
            ++ currentSize;
        }
        else {
            if (currentSize > maxSize) {
                maxSize = currentSize;
                maxStart = currentStart;
            }

            currentStart = i;
            currentSize = 1;
        }
    }
    if (currentSize > maxSize) {
        maxSize = currentSize;
        maxStart = currentStart;
    }

    std::cout << maxStart << " " << maxStart + maxSize - 1 << std::endl;

    return 0;
}

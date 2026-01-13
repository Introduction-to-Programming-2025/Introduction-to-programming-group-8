#include <iostream>

int main() {
    size_t m, n;
    std::cin >> m >> n;

    unsigned* coins = new unsigned[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    unsigned* sums = new unsigned[m + 1];

    for (size_t i = 0; i <= m; ++i) {
        sums[i] = 0;
    }

    sums[0] = 1;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (sums[j] && j + coins[i] <= m) {
                sums[j + coins[i]] += sums[j];
            }
        }
    }

    for (size_t i = 0; i <= m; ++i) {
        std::cout << sums[i] << " ";
    }
    std::cout << std::endl;

    std::cout << sums[m] << std::endl;

    delete[] sums;
    delete[] coins;

    return 0;
}

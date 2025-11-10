#include <iostream>

const double EPS = 1e-6;

int main() {
    size_t n;
    std::cin >> n;

    int codes[256];
    double prices[256];
    int count[51] = {0};
    double totalPrice[51] = {0};

    for (size_t i = 0; i < n; ++i) {
        std::cin >> codes[i];
    }

    for (size_t i = 0; i < n; ++i) {
        std::cin >> prices[i];
    }

    for (size_t i = 0; i < n; ++i) {
        ++count[codes[i]];
        totalPrice[codes[i]] += prices[i];
    }

    for (size_t i = 0; i <= 50; ++i) {
        if (count[i] > 0) {
            std::cout << i << " " << count[i] << std::endl;
        }
    }

    double maxCost = -1;
    int maxCostProductCode = -1;

    for (size_t i = 0; i <= 50; ++i) {
        if (count[i] > 0) {
            if (totalPrice[i] > maxCost + EPS) {
                maxCost = totalPrice[i];
                maxCostProductCode = i;
            }
        }
    }

    std::cout << maxCostProductCode << std::endl;

    return 0;
}

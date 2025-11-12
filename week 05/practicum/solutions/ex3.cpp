#include <iostream>

int main() {
    const size_t MAX_SIZE = 1024;

    size_t n, k;
    int arr[MAX_SIZE];

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cin >> k;

    // а)
    if (k > n || k <= 0) {
        std::cout << "k е извън допустимите граници." << std::endl;
    } else {
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - 1 - i; ++j) {
                if (arr[j] < arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        std::cout << arr[k - 1] << std::endl;
    }

    // б)
    for (size_t i = 0; i < n; ++i) {
        size_t count = 0;

        for (size_t j = i + 1; j < n; ++j) {
            if (arr[j] < arr[i]) {
                ++count;
            }
        }
        std::cout << count << " ";
    }

    std::cout << std::endl;

    return 0;
}

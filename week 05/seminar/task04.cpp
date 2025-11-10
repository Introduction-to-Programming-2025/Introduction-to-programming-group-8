#include <iostream>

int main() {
    const size_t MAX_SIZE = 1024;
    unsigned int array[MAX_SIZE];
    size_t n;

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    unsigned int maxVolume = 0, volume;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            unsigned int height = array[i] < array[j] ? array[i] : array[j];
            unsigned int dist = j - i;

            volume = height * dist;

            if (volume > maxVolume) {
                maxVolume = volume;
            }
        }
    }

    std::cout << maxVolume * 1000 << std::endl;

    return 0;
}

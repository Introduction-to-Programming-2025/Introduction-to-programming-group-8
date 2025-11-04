#include <iostream>

int main() {
    const size_t MAX_SIZE = 128;
    double array[MAX_SIZE];
    size_t n;

    std::cin >> n;
    for  (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    double sum = 0;
    size_t i = 0;

    while (i < n)  {
        if (array[i] < 0) {
            break;
        }

        sum += array[i];
        ++i;
    }

    std::cout << sum << std::endl;


    return 0;
}

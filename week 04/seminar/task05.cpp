#include <iostream>

int main() {
    const size_t MAX_SIZE = 1024;
    size_t n, k;
    unsigned int array[MAX_SIZE];

    std::cin >> n >> k;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    size_t printed = 0, i = 0;  
    while (printed < n) {
        std::cout << array[i] << " ";
        i += k;
        ++ printed;

        if (i >= n) {
            i %= n;
        }
    }
    std::cout << std::endl;


    return 0;
}

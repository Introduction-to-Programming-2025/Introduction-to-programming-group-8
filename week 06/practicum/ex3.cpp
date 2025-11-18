#include <iostream>

const int MAX_SIZE = 1024;

void merge(const int a[], size_t aLength, const int b[], size_t bLength, int c[]) {
    int leftCurrentIndex = 0;
    int rightCurrentIndex = 0;
    int resultIndex = 0;

    while (leftCurrentIndex < aLength && rightCurrentIndex < bLength) {
        if (a[leftCurrentIndex] <= b[rightCurrentIndex]) {
            c[resultIndex] = a[leftCurrentIndex];
            ++leftCurrentIndex;
        } else {
            c[resultIndex] = b[rightCurrentIndex];
            ++rightCurrentIndex;
        }
        ++resultIndex;
    }

    while (leftCurrentIndex < aLength) {
        c[resultIndex] = a[leftCurrentIndex];
        ++leftCurrentIndex;
        ++resultIndex;
    }

    while (rightCurrentIndex < bLength) {
        c[resultIndex] = b[rightCurrentIndex];
        ++rightCurrentIndex;
        ++resultIndex;
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    if (n < 0 || n > MAX_SIZE || m < 0 || m > MAX_SIZE) {
        return -1;
    }

    int a[MAX_SIZE];
    int b[MAX_SIZE];
    int c[2 * MAX_SIZE];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (size_t i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    merge(a, n, b, m, c);

    for (size_t i = 0; i < n + m; ++i) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

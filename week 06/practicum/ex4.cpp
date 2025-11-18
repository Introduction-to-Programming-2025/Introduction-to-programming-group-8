#include <iostream>

const size_t MAX_SIZE = 1024;

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

void mergeSort(int arr[], size_t n) {
    if (n <= 1) {
        return;
    }

    int temp[MAX_SIZE];

    for (size_t width = 1; width < n; width *= 2) {
        for (size_t i = 0; i < n; i += 2 * width) {
            size_t leftStart = i;
            size_t leftLen = width;

            size_t rightStart = i + width;
            size_t rightLen = 0;

            if (leftStart + leftLen > n) {
                leftLen = n - leftStart;
            }

            if (rightStart < n) {
                rightLen = width;
                if (rightStart + rightLen > n) {
                    rightLen = n - rightStart;
                }
            }

            merge(arr + leftStart, leftLen, arr + rightStart, rightLen, temp + leftStart);
        }

        for (size_t i = 0; i < n; ++i) {
            arr[i] = temp[i];
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    if (n < 0 || n > MAX_SIZE) {
        return -1;
    }

    int arr[MAX_SIZE];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    mergeSort(arr, n);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

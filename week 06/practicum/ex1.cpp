#include <iostream>

void printLongestEqualSequence(const int* arr, int n) {
    if (n <= 0) {
        return;
    }

    int bestStart = 0;
    int bestLen = 1;

    int curStart = 0;
    int curLen = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == arr[i - 1]) {
            ++curLen;
        } else {
            if (curLen > bestLen) {
                bestLen = curLen;
                bestStart = curStart;
            }
            curStart = i;

            curLen = 1;
        }
    }

    if (curLen > bestLen) {
        bestLen = curLen;
        bestStart = curStart;
    }

    std::cout << bestStart << " " << bestLen;
}

int main() {
    const size_t MAX_SIZE = 1024;

    int n;
    std::cin >> n;

    if (n < 0 || n > MAX_SIZE) {
        return -1;
    }

    int arr[MAX_SIZE];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    printLongestEqualSequence(arr, n);

    return 0;
}

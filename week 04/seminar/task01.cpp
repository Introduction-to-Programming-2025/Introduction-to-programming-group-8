#include <iostream>

int main() {
    const size_t MAX_SIZE = 128;

    int arrayA[MAX_SIZE], arrayB[MAX_SIZE];
    size_t n, m;

    std::cin >> n;
    for  (size_t i = 0; i < n; ++i) {
        std::cin >> arrayA[i];
    }

    std::cin >> m;
    for (size_t i = 0; i < m; ++i) {
        std::cin >> arrayB[i];
    }

    int arrayC[2 * MAX_SIZE];
    size_t k = 0, i = 0, j = 0;

    // докато сме в рамките и на двата масива
    while (i < n && j < m) {
        if (arrayA[i] < arrayB[j]) {
            arrayC[k] = arrayA[i];
            ++i;
        } 
        else {
            arrayC[k] = arrayB[j];
            ++j;
        }

        ++k;
    }

    // единият масив е приключил
    while (i < n) {
        arrayC[k] = arrayA[i];
        ++i;
        ++k;
    }

    while (j < m) {
        arrayC[k] = arrayB[j];
        ++j;
        ++k;
    }

    for (size_t i = 0; i < n + m; ++i){
        std::cout << arrayC[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
size_t k = 0;
int i = n - 1, j = m - 1;

    // докато сме в рамките и на двата масива
    while (i >= 0 && j >= 0) {
        if (arrayA[i] > arrayB[j]) {
            arrayC[k] = arrayA[i];
            --i;
        } 
        else {
            arrayC[k] = arrayB[j];
            --j;
        }

        ++k;
    }

    // единият масив е приключил
    while (i >= 0) {
        arrayC[k] = arrayA[i];
        --i;
        ++k;
    }

    while (j >= 0) {
        arrayC[k] = arrayB[j];
        --j;
        ++k;
    }

*/
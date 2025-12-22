#include <iostream>
const size_t MAX_SIZE = 128;

void printSpiral(int matrix[MAX_SIZE][MAX_SIZE], const size_t rows, const size_t columns) {
    // добавя се единица спрямо четността
    for (int t = 0; t < columns / 2 + columns % 2; ++t) { 
        size_t lastRow = rows - t - 1, lastColumn = columns - t - 1;

        // горна страна
        for (size_t j = t; j < lastColumn; ++j) {
            std::cout << matrix[t][j] << " ";
        }

        // дясна страна
        for (size_t i = t ; i < lastRow; ++i) {
            std::cout << matrix[i][lastColumn] << " ";
        }

        // долна страна
        for (size_t j = lastColumn; j > t; --j) {
            std::cout << matrix[lastRow][j] << " ";
        }

        // лява страна
        for (size_t i = lastRow; i > t; --i) {
            std::cout << matrix[i][t] << " ";
        }
    }

    std::cout << std::endl;
}


int main(){
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    printSpiral(matrix, n, n);

    return 0;
}

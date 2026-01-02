#include <iostream>
const size_t MAX_COLS = 128, MAX_ROWS = 2;

bool lessThan(int row1[], int row2[], const size_t columns) {
    for (size_t i = 0; i < columns; ++i) {
        if (row1[i] == row2[i]) {
            continue;
        }

        return row1[i] < row2[i];
    }

    // при равни
    return false;
}

void swap(int row1[], int row2[], const size_t columns) {
    for (size_t i = 0; i < columns; ++i) {
        std::swap(row1[i], row2[i]);
    }
}


void sortMatrix(int matrix[MAX_COLS][MAX_COLS], const size_t rows, const size_t columns){
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = i + 1; j < rows; ++j) {
            if (lessThan(matrix[j], matrix[i], columns)) {
                swap(matrix[i], matrix[j], columns);
            }
        }
    }
}


int main(){
    int matrix[MAX_COLS][MAX_COLS];
    size_t n, m = 2;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    sortMatrix(matrix, n, m);

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

#include <iostream>
const size_t MAX_SIZE = 128;

int sumMatrix(int matrix[MAX_SIZE][MAX_SIZE], const size_t rows, const size_t columns) {
    int sum = 0;

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            sum += matrix[i][j];
        }
    }


    return sum;
}

int submatrixSum(int matrix[MAX_SIZE][MAX_SIZE], const size_t rows, const size_t columns,
    const size_t subRows, const size_t subColumns, size_t startRow, size_t startColumn) {
    int submatrix[MAX_SIZE][MAX_SIZE];

    for (size_t i = 0; i < subRows; ++i) {
        for (size_t j = 0; j < subColumns; ++j) {
            submatrix[i][j] = matrix[startRow + i][startColumn + j];
        }
    }

    return sumMatrix(submatrix, subRows, subColumns);
}


int maxSubmatrixSum(int matrix[MAX_SIZE][MAX_SIZE], 
    const size_t rows, const size_t columns,
    const size_t subRows, const size_t subColumns) {
    int maxSum = 0;

    for (size_t i = 0; i < rows - subRows + 1; ++i) {
        for (size_t j = 0; j < columns - subColumns + 1; ++j) {
            int sum = submatrixSum(matrix, rows, columns, subRows, subColumns, i, j);

            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }

    return maxSum;
}


int main(){
    int matrix[MAX_SIZE][MAX_SIZE];
    size_t n, m, p, q;
    std::cin >> n >> m;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cin >> p >> q;

    std::cout << maxSubmatrixSum(matrix, n, m, p, q) << std::endl;

    return 0;
}

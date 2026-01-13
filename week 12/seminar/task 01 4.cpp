#include <iostream>

void deleteMatrix(int** &matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void traverse(int** matrix, size_t rows, size_t cols,
    size_t currentRow, size_t currentCol, int areaNumber) {
    if (matrix[currentRow][currentCol] <= 0) {
        return;
    }

    matrix[currentRow][currentCol] = areaNumber;

    // right
    if (currentCol < cols - 1) {
        traverse(matrix, rows, cols, currentRow, currentCol + 1, areaNumber);
    }

    // down
    if (currentRow < rows - 1) {
        traverse(matrix, rows, cols, currentRow + 1, currentCol, areaNumber);
    }

    // left
    if (currentCol > 0) {
        traverse(matrix, rows, cols, currentRow, currentCol - 1, areaNumber);
    }

    // up
    if (currentRow > 0) { 
        traverse(matrix, rows, cols, currentRow - 1, currentCol, areaNumber);
    }
}

int areas(int** matrix, size_t rows, size_t cols) {
    // Създава се копие на матрицата, за да не се променя оригиналната
    int** matrixCopy = new int*[rows];

    for (size_t i = 0; i < rows; ++i) {
        matrixCopy[i] = new int[cols];
        for (size_t j = 0; j < cols; ++j) {
            matrixCopy[i][j] = matrix[i][j];
        }
    }

    int areaNumber = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (matrixCopy[i][j] > 0) {
                areaNumber --;
                traverse(matrixCopy, rows, cols, i, j, areaNumber);
            }
        }
    }

    deleteMatrix(matrixCopy, rows);

    return -1 * areaNumber;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    int** matrix = new int*[n];

    for (size_t i = 0; i < n; ++i) {
        matrix[i] = new int[m];
        for (size_t j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << areas(matrix, n, m) << std::endl;

    deleteMatrix(matrix, n);

    return 0;
}

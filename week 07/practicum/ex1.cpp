#include <iostream>

const size_t MAX_SIZE = 1024;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], const size_t& rows, const size_t& cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << endl;
    }
}

bool multiplyMatrices(int A[MAX_SIZE][MAX_SIZE], int B[MAX_SIZE][MAX_SIZE], int C[MAX_SIZE][MAX_SIZE],
        const size_t& rowsA, const size_t& colsA, const size_t& rowsB, const size_t& colsB) {
    if (colsA != rowsB) {
        std::cout << "Грешка: Колоните на първата трябва да съвпадат с редовете на втората." << std::endl;
        return false;
    }

    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            C[i][j] = 0;
        }
    }

    for (size_t i = 0; i < rowsA; ++i) {
        for (size_t j = 0; j < colsB; ++j) {
            for (size_t k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return true;
}

bool inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], size_t& rows, size_t& cols) {
    std::cout << "Въведете размерите на първата матрица (редове и колони): ";
    std::cin >> rows >> cols;

    if (rows > MAX_SIZE || cols > MAX_SIZE) {
        std::cout << "Грешка: Размерите на първата матрица надвишават максималния размер." << std::endl;
        return false;
    }

    std::cout << "Въведете елементите на матрица:" << std::endl;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    
    return true;
}

int main() {
    size_t rowsA, colsA, rowsB, colsB;
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];

    if(!inputMatrix(A, rowsA, colsA) || !inputMatrix(B, rowsB, colsB)) {
        return -1;
    }

    int C[MAX_SIZE][MAX_SIZE];

    if (multiplyMatrices(A, B, C, rowsA, colsA, rowsB, colsB)) {
        std::cout << "Резултат от умножението на матриците:" << std::endl;
        printMatrix(C, rowsA, colsB);
    }

    return 0;
}

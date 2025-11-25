#include <iostream>

const size_t MAX_SIZE = 1024;

void printMatrix(int matrix[MAX_SIZE][MAX_SIZE], const size_t& n) {
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool isBalanced(int matrix[MAX_SIZE][MAX_SIZE], const size_t& n) {
    int sumAboveDiagonal = 0, sumBelowDiagonal = 0;
    int sumMainDiagonal = 0, sumSecondaryDiagonal = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i < j) {
                sumAboveDiagonal += matrix[i][j];
            } else if (i > j) {
                sumBelowDiagonal += matrix[i][j];
            }

            if (i == j) {
                sumMainDiagonal += matrix[i][j];
            }

            if (i + j == n - 1) {
                sumSecondaryDiagonal += matrix[i][j];
            }
        }
    }

    return (sumAboveDiagonal == sumBelowDiagonal) && (sumMainDiagonal == sumSecondaryDiagonal);
}

int main() {
    size_t n;

    std::cout << "Въведете размер на квадратната матрица (n x n): ";
    std::cin >> n;

    if (n > MAX_SIZE) {
        std::cout << "Грешка: Размерът на матрицата не може да надвишава " << MAX_SIZE << "." << std::endl;
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    std::cout << "Въведете елементите на матрицата (" << n << " x " << n << "):" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    if (isBalanced(matrix, n)) {
        std::cout << "Матрицата е балансирана." << std::endl;
    } else {
        std::cout << "Матрицата не е балансирана." << std::endl;
    }

    return 0;
}

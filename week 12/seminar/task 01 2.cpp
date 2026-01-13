#include <iostream>

const char EMPTY = '.', WALL = '-';

void deleteMatrix(char** &matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool traverse(char** labyrinth, size_t rows, size_t cols,
    size_t currentRow, size_t currentCol, size_t endingRow, size_t endingCol) {
    if (currentRow == endingRow && currentCol == endingCol) {
        return true;
    }

    if (labyrinth[currentRow][currentCol] == WALL) {
        return false;
    }

    labyrinth[currentRow][currentCol] = WALL;

    // right
    if (currentCol < cols - 1 && 
        traverse(labyrinth, rows, cols, currentRow, currentCol + 1, endingRow, endingCol)) {
        return true;
    }

    // down
    if (currentRow < rows - 1 && 
        traverse(labyrinth, rows, cols, currentRow + 1, currentCol, endingRow, endingCol)) {
        return true;
    }

    // left
    if (currentCol > 0 && 
        traverse(labyrinth, rows, cols, currentRow, currentCol - 1, endingRow, endingCol)) {
        return true;
    }

    // up
    if (currentRow > 0 && 
        traverse(labyrinth, rows, cols, currentRow - 1, currentCol, endingRow, endingCol)) {
        return true;
    }

    labyrinth[currentRow][currentCol] = EMPTY;

    return false;
}

bool findPath(char** labyrinth, size_t rows, size_t cols,
    size_t startingRow, size_t startingCol, size_t endingRow, size_t endingCol) {
    // Създава се копие на матрицата, за да не се променя оригиналната
    char** labyrinthCopy = new char*[rows];

    for (size_t i = 0; i < rows; ++i) {
        labyrinthCopy[i] = new char[cols];
        for (size_t j = 0; j < cols; ++j) {
            labyrinthCopy[i][j] = labyrinth[i][j];
        }
    }

    bool result = traverse(labyrinthCopy, rows, cols, startingRow, startingCol, endingRow, endingCol);

    deleteMatrix(labyrinthCopy, rows);

    return result;
}

int main() {
    size_t n, m;
    std::cin >> n >> m;

    char** labyrinth = new char*[n];

    for (size_t i = 0; i < n; ++i) {
        labyrinth[i] = new char[m];
        for (size_t j = 0; j < m; ++j) {
            std::cin >> labyrinth[i][j];
        }
    }

    std::cout << (findPath(labyrinth, n, m, 0, 0, n - 1, m - 1) ? "Yes" : "No") << std::endl;

    deleteMatrix(labyrinth, n);

    return 0;
}

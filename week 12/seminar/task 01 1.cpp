#include <iostream>

const char EMPTY = '.', WALL = '-';

bool findPath(char** labyrinth, size_t rows, size_t cols,
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
        findPath(labyrinth, rows, cols, currentRow, currentCol + 1, endingRow, endingCol)) {
        return true;
    }

    // down
    if (currentRow < rows - 1 && 
        findPath(labyrinth, rows, cols, currentRow + 1, currentCol, endingRow, endingCol)) {
        return true;
    }

    // left
    if (currentCol > 0 && 
        findPath(labyrinth, rows, cols, currentRow, currentCol - 1, endingRow, endingCol)) {
        return true;
    }

    // up
    if (currentRow > 0 && 
        findPath(labyrinth, rows, cols, currentRow - 1, currentCol, endingRow, endingCol)) {
        return true;
    }

    labyrinth[currentRow][currentCol] = EMPTY;

    return false;
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


    for (size_t i = 0; i < n; ++i) {
        delete[] labyrinth[i];
    }
    delete[] labyrinth;

    return 0;
}

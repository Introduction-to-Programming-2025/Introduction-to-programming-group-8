#include <iostream>

void deleteMatrix(int** &matrix, int &rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
    rows = 0;
}

void addNumber(int** hexagon, int row, int col, int &number, int maxNumber, int &iMax, int &jMax) {
    hexagon[row][col] = number;
    ++number;
    if (number == maxNumber) {
        iMax = row;
        jMax = col;
    }
}

void print(int** hexagon, int n) {
    int cols = n;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << hexagon[i][j] << " ";
        }
        std::cout << std::endl;
        cols++;
    }

    cols -= 2;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << hexagon[n + i][j] << " ";
        }
        cols--;
        std::cout << std::endl;
    }
}

int main() {
    int n, m, s, p, q;

    std::cin >> n >> m >> s >> p >> q;

    int rows = 2 * n - 1;
    int** hexagon = new int*[rows];


    for (int i = 0; i < n; ++i) {
        hexagon[i] = new int[n + i];
    }
    for (int i = 0; i < n - 1; ++i) {
        hexagon[rows - 1 - i] = new int[n + i];
    }

    int number = s;
    int maxNumber = s + m - 1;
    int iMax, jMax;
    for(int t = 0; t < n; ++t) {
        // горен хоризонтал
        for (int i = t; i < n; i++) {
            hexagon[t][i] = number;
            addNumber(hexagon, t, i, number, maxNumber, iMax, jMax);
        }

        // десни диагонали 
        for(int i = 1 + t; i < n; ++i) {
            addNumber(hexagon, i, n + i - t - 1, number, maxNumber, iMax, jMax);
        }

        for(int i = 1; i < n - t; ++i) {
            hexagon[n + i - 1][rows - i - 1 - t] = number;
            addNumber(hexagon, n + i - 1, rows - i - 1 - t, number, maxNumber, iMax, jMax);
        }

        // долен хоризонтар
        for (int i = n - 2; i >= t; --i) {
            hexagon[rows - 1 - t][i] = number;
            addNumber(hexagon, rows - 1 - t, i, number, maxNumber, iMax, jMax);
        }

        // леви диагонали
        for (int i = rows - 2 - t; i >= 1 + t; --i) {
            hexagon[i][t] = number;
            addNumber(hexagon, i, t, number, maxNumber, iMax, jMax);
        }
    }
    

    print(hexagon, n);

    // номерацията започва от 1 в задачата
    std::cout << hexagon[p - 1][q - 1] << std::endl << iMax + 1 << " " << jMax + 1 << std::endl;

    deleteMatrix(hexagon, rows);

    return 0;
}

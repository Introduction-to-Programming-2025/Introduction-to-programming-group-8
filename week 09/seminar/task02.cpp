#include <iostream>

void deleteMatrix(int** &matrix, size_t &rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;
}

void addPair(int x, int y, int** &array, size_t &size) {
    int** temp = new int*[size + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = new int[2];
        temp[i][0] = array[i][0];
        temp[i][1] = array[i][1];
    }

    temp[size] = new int[2];
    temp[size][0] = x;
    temp[size][1] = y;

    deleteMatrix(array, size);
    array = temp;
    ++size;
}

void shiftLeft(int** &array, size_t &size) {
    int* temp = array[0];

    for (size_t i = 0; i < size - 1; ++i) {
        array[i] = array[i + 1];
    }

    --size;
    delete[] temp;
}

void print(int** matrix, size_t rows, size_t cols) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    size_t n, m, t;
    std::cin >> n >> m >> t;
    int** matrix = new int*[n];
    for(size_t i=0;i<n;++i)
    {
        matrix[i]= new int[m];
        for(size_t j=0;j<m;++j)
        {
            matrix[i][j]=-1;
        }
    }

    int** queue = nullptr;
    size_t qSize = 0;

    for (size_t i = 0; i < 2; ++i) {
        size_t p, q;
        std::cin >> p >> q;
        matrix[p][q] = 0;

        addPair(p, q, queue, qSize);
    }

    while(qSize > 0) {
        int x = queue[0][0];
        int y = queue[0][1];
        shiftLeft(queue, qSize);
        
        int day = matrix[x][y] + 1;
        if (day <= t) {
            if (x > 0 && (matrix[x - 1][y] == -1 || matrix[x - 1][y] > day)) {
                matrix[x - 1][y] = day;
                addPair(x - 1, y, queue, qSize);
            }
            if (x < n - 1 && (matrix[x + 1][y] == -1 || matrix[x + 1][y] > day)) {
                matrix[x + 1][y] = day;
                addPair(x + 1, y, queue, qSize);
            }
            if (y > 0 && (matrix[x][y - 1] == -1 || matrix[x][y - 1] > day)) {
                matrix[x][y - 1] = day;
                addPair(x, y - 1, queue, qSize);
            }
            if (y < m - 1 && (matrix[x][y + 1] == -1 || matrix[x][y + 1] > day)) {
                matrix[x][y + 1] = day;
                addPair(x, y + 1, queue, qSize);
            }
        }
    }

    int cnt = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (matrix[i][j] == -1) {
                cnt++;
            }
        }
    }

    std::cout << cnt << std::endl;

    print(matrix, n, m);

    deleteMatrix(matrix,n);
    delete[] queue;
    return 0;
}

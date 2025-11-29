#include <iostream>

void populateMatrix(int** &matrix, size_t rows, size_t cols) {
    matrix = new int*[rows];

    for (size_t i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];

        for (size_t j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j + 1;
        }
    }
}

void deleteMatrix(int** &matrix, size_t rows) {
    for (size_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    
    delete[] matrix;
}

void addElement(int element, int* &array, size_t &size) {
    int* temp = new int[size + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = array[i];
    }

    temp[size] = element;

    delete[] array;
    array = temp;
    size++;
}

void populatePrimes(int* &primes, size_t &primesSize, int maxNumber) {
    primes = nullptr;
    primesSize = 0;

    for (int i = 2; i <= maxNumber; ++i) {
        bool prime = true;
        
        for (size_t j = 0; j < primesSize && prime; ++j) {
            prime = i % primes[j];
        }

        if (prime) {
            addElement(i, primes, primesSize);
        }
    }
}

bool isPrime(int number, int* primes, size_t primesSize) {
    for (size_t i = 0; i < primesSize; ++i) {
        if (primes[i] == number) {
            return true;
        }
    }

    return false;
}

int color(
    int** matrix, size_t rows, size_t cols, 
    size_t pi, size_t pj,
    int* primes, size_t primesSize
) {
    int colored = 1;
    bool step = true;

    while (step) {
        step = false;

        // движение наляво за Аня
        if (pj + 1 < cols && isPrime(matrix[pi][pj + 1], primes, primesSize)) {
            pj++;
            step = true;
            colored++;
        }
        else if (pj + 2 < cols && isPrime(matrix[pi][pj + 2], primes, primesSize)) {
            pj += 2;
            step = true;
            colored++;
        }
        // движение по диагонал надясно за Аня
        else if (pj - 1 >= 0 && pi + 1 < rows && isPrime(matrix[pi + 1][pj - 1], primes, primesSize)) {
            pi++;
            pj--;
            step = true;
            colored++;
        }
        else if (pj - 2 >= 0 && pi + 2 < rows && isPrime(matrix[pi + 2][pj - 2], primes, primesSize)) {
            pi += 2;
            pj -= 2;
            step = true;
            colored++;
        }
        // движение напред за Аня
        if (pi + 1 < rows && isPrime(matrix[pi + 1][pj], primes, primesSize)) {
            pi++;
            step = true;
            colored++;
        }
        else if (pi + 2 < rows && isPrime(matrix[pi + 2][pj], primes, primesSize)) {
            pi += 2;
            step = true;
            colored++;
        }
    }

    return colored;
}

int main() {
    size_t n, rows, cols, optimalR, optimalC, primesSize;

    std::cin >> n;

    int** matrix;
    int* primes;
    populatePrimes(primes, primesSize, n);

    int maxColored = 0;

    for (size_t i = 1; i <= n; ++i) {
        if (n % i == 0) {
            rows = i;
            cols = n / i;
            populateMatrix(matrix, rows, cols);
            int colored = color(matrix, rows, cols, 0, 1, primes, primesSize);

            if (colored > maxColored) {
                maxColored = colored;
                optimalR = rows;
                optimalC = cols;
            }

            deleteMatrix(matrix, rows);
        }
    }

    std::cout << "Size: " << optimalR << "x" << optimalC << "; Colored: " << maxColored << std::endl;

    delete[] primes;

    return 0;
}

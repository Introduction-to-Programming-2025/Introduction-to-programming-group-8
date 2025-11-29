#include <iostream>

void deleteMatrix(int** &histogram, size_t size) {
    if (histogram == nullptr) {
        return;
    }

    for (size_t i = 0; i < size; ++i) {
        delete[] histogram[i];
    }

    delete[] histogram;
    histogram = nullptr;
}

void printMatrix(int** histogram, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << (char)histogram[i][0] << " " << histogram[i][1] << std::endl;
    }
}

void addSymbol(const char symbol, int** &histogram, size_t &size) {
    // заделяне на нова памет с един допълнителен елемент
    int** temp = new int*[size + 1];

    // копиране на текущите елементи
    for (size_t i = 0; i < size; ++i) {
        temp[i] = new int[2];
        temp[i][0] = histogram[i][0];
        temp[i][1] = histogram[i][1];
    }

    // добавяне н нов елемент в края на масива
    temp[size] = new int[2];
    temp[size][0] = symbol;
    temp[size][1] = 1;

    // пренасочване на указателя
    deleteMatrix(histogram, size);

    histogram = temp;
    size++;
}

void countSymbol(const char symbol, int** &histogram, size_t &size) {
    for (size_t i = 0; i < size; ++i) {
        if (histogram[i][0] == symbol) {
            histogram[i][1] ++;
            return;
        }
    }

    addSymbol(symbol, histogram, size);
}


int main() {
    size_t size;
    std::cin >> size;
    char* array = new char[size];

    for (size_t i = 0; i < size; ++i) {
        std::cin >> array[i];
    }

    size_t n = 0;
    int** histogram = nullptr;

    for (size_t i = 0; i < size; ++i) {
        countSymbol(array[i], histogram, n);
    }

    printMatrix(histogram, n);
    
    deleteMatrix(histogram, n);
    delete[] array;

    return 0;
}

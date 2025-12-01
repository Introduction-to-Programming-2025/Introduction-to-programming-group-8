#include <iostream>

void resize(int *&arr, size_t &oldSize, size_t newSize)
{
    int *newArr = new int[newSize];

    size_t limit = (oldSize < newSize) ? oldSize : newSize;
    for (size_t i = 0; i < limit; ++i)
    {
        newArr[i] = arr[i];
    }

    for (size_t i = limit; i < newSize; ++i)
    {
        newArr[i] = 0;
    }

    delete[] arr;
    arr = newArr;
    oldSize = newSize;
}

void printArray(int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    size_t n = 5;
    int *a = new int[n];

    for (size_t i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }

    std::cout << "Original: ";
    printArray(a, n);

    resize(a, n, 8);

    std::cout << "Resized bigger: ";
    printArray(a, n);

    resize(a, n, 3);

    std::cout << "Resized smaller: ";
    printArray(a, n);

    delete[] a;
    return 0;
}

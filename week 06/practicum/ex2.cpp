#include <iostream>


bool isPrime(size_t x) {
    if (x <= 1) {
        return false;
    }

    if(x == 2) {
        return true;
    }

    if(x % 2 == 0) {
        return false;
    }

    for(size_t div = 3; div * div <= x; div+=2) {
        if(x % div == 0) {
            return false;
        }
    }

    return true;
}

size_t rearrangePrimesFirst(size_t arr[], size_t n) {
    size_t writeIndex = 0;
    size_t primesCount = 0;

    for(size_t i = 0; i < n; ++i) {
        if(isPrime(arr[i])) {
            if(i != writeIndex) {
                arr[i] += arr[writeIndex];
                arr[writeIndex] = arr[i] - arr[writeIndex];
                arr[i] -= arr[writeIndex];
            }
        }

        ++writeIndex;
        ++primesCount;
    }

    return primesCount;
}

int main() {
    const size_t MAX_SIZE = 1024;

    int n;
    std::cin >> n;

    if (n < 0 || n > MAX_SIZE) {
        return -1;
    }

    size_t arr[MAX_SIZE];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int primesCount = rearrangePrimesFirst(arr, n);

    for (size_t i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << primesCount << std::endl;

    return 0;
}
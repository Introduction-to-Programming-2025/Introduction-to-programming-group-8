#include <iostream>

bool isPrime(const unsigned number, const unsigned primes[], const size_t primesSize
) {
    for (size_t i = 0; i < primesSize && primes[i] < number; ++i) {
        if (number % primes[i] == 0) {
            return false;
        }
    }

    return true;
}

void generatePrimes(unsigned primes[], size_t& primesSize, const unsigned maxNumber) {
    primesSize = 0;

    for (unsigned i = 2; i <= maxNumber; ++i) {
        if (isPrime(i, primes, primesSize)) {
            primes[primesSize] = i;
            ++primesSize;
        }
    }
}

unsigned sumOfDigits(unsigned number) {
    unsigned sum = 0;

    while (number > 0) {
        short digit = number % 10;
        number /= 10;

        sum += digit;
    }

    return sum;
}


void printDoubleprimeNumbers(const unsigned minNumber, const unsigned maxNumber) {
    unsigned primes[maxNumber];
    size_t primesSize;

    generatePrimes(primes, primesSize, maxNumber);

    for (size_t i = 0; i < primesSize; ++i) {
        if (primes[i] >= minNumber && isPrime(sumOfDigits(primes[i]), primes, primesSize)) {
            std::cout << primes[i] << " ";
        }
    }

    std::cout << std::endl;
}


int main() {
    unsigned intervalStart, intervalEnd;

    std::cin >> intervalStart >> intervalEnd;

    printDoubleprimeNumbers(intervalStart, intervalEnd);


    return 0;
}
#include <iostream>

// подаване на променливи по референция:
// стойността им се променя
void swap(int& x, int& y) {
    int z = x;
    x = y;
    y = z;
}

// подаване на променливи по стойност:
// работи се с копие на стойността, оригиналните променливи не се променят
int GCD(int x, int y) {
    while(y > 1) {
        if (x > y) {
            swap(x, y);
        }

        y %= x;
    }

    return x;
}

int LCM(int x, int y) {
    // функцията трябва да е декларирана преди текущата, за да бъде извикана
    return (x * y) / GCD(x, y);
}

int main() {
    size_t n;
    int array[128];

    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int arrayGCD = array[0], arrayLCM = array[0];

    for (size_t i = 1; i < n; ++i) {
        arrayGCD = GCD(arrayGCD, array[i]);
        arrayLCM = LCM(arrayLCM, array[i]);
    }

    std::cout << "GCD: " << arrayGCD << std::endl;
    std::cout << "LCM: " << arrayLCM << std::endl;


    return 0;
}
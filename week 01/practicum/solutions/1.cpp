#include <iostream>

int main() {
    double weightKg = 0, heightCm = 0;

    std::cin >> weightKg >> heightCm;

    double h = heightCm / 100.0;
    double bmi = weightKg / (h * h);

    std::cout << bmi << std::endl;

    return 0;
}

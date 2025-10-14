#include <iostream>
#include <cmath>

int main() {
    double a = 0, b = 0, c = 0;

    std::cin >> a >> b >> c;

    bool aIsZero = a == 0.0;
    bool bIsZero = b == 0.0;
    bool isQuadratic = !aIsZero;
    bool isLinear = aIsZero && !bIsZero;
    bool isConstant = aIsZero && bIsZero;

    double discriminant = b * b - 4.0 * a * c;
    bool nonnegativeDiscriminant = discriminant >= 0.0;

    // +1, ако дискриминантата е >= 0, иначе -1
    int sign = (discriminant >= 0.0) - (discriminant < 0.0);

    // ако дискриминантата е отрицателна, sqrt ще ни върне грешка. Затова тогава трябва да умножим по -1. 
    // Иначе, че умножим по 1, което не променя дискриминантата и съответно нения корен квадратен.
    double sqrtDiscriminant = sqrt(discriminant * sign);

    isConstant && (c == 0) && std::cout << "All real numbers are roots" << std::endl;
    isConstant && (c != 0) && std::cout << "No roots" << std::endl;

    isLinear && std::cout << "x = " << (-c / b) << std::endl;

    isQuadratic && !nonnegativeDiscriminant && std::cout << "Discriminant: " << discriminant << std::endl;

    isQuadratic && nonnegativeDiscriminant && std::cout << "x1 = " << ((-b - sqrtDiscriminant) / (2.0 * a)) << std::endl;
    isQuadratic && nonnegativeDiscriminant && (sqrtDiscriminant != 0) && std::cout << "x2 = " << ((-b + sqrtDiscriminant) / (2.0 * a)) << std::endl;

    return 0;
}

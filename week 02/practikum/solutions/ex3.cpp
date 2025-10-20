#include <iostream>

int main() {
    const double EPSILON = 0.0001;

    double num1, num2, num3, num4, num5;
    std::cin >> num1 >> num2 >> num3 >> num4 >> num5;

    if (((num2 >= num1 - EPSILON && num2 >= num3 - EPSILON) || (num2 <= num1 + EPSILON && num2 <= num3 + EPSILON)) &&
        ((num3 >= num2 - EPSILON && num3 >= num4 - EPSILON) || (num3 <= num2 + EPSILON && num3 <= num4 + EPSILON)) &&
        ((num4 >= num3 - EPSILON && num4 >= num5 - EPSILON) || (num4 <= num3 + EPSILON && num4 <= num5 + EPSILON))) {
        std::cout << "yes\n";
    }
    else {
        std::cout << "no\n";
    }
    return 0;
}

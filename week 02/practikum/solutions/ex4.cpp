#include <iostream>

int main() {
    const double EPSILON = 0.0001;

    double radius, x, y;
    std::cin >> radius >> x >> y;

    double radiusSquared = radius * radius;
    double distanceSquared = x * x + y * y;

    if (std::abs(distanceSquared - radiusSquared) < EPSILON) {
        std::cout << "по контура\n";
    } else if (distanceSquared < radiusSquared) {
        std::cout << "вътре\n";
    } else {
        std::cout << "отвън\n";
    }
    return 0;
}

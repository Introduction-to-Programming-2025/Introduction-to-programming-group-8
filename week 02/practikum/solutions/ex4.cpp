#include <iostream>

int main() {
    double radius, x, y;
    std::cin >> radius >> x >> y;

    double radiusSquared = radius * radius;
    double distanceSquared = x * x + y * y;

    if (distanceSquared - radiusSquared == 0) {
        std::cout << "по контура\n";
    } else if (distanceSquared < radiusSquared) {
        std::cout << "вътре\n";
    } else {
        std::cout << "отвън\n";
    }
    return 0;
}

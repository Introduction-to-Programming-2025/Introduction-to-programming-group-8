#include <iostream>
#include <cmath>

int main() {
    char kind;
    std::cin >> kind;

    const double PI = 3.141592;
    double a = 0.0, b = 0.0, r = 0.0, h = 0.0, area = 0.0;

    switch (kind) {
        case 's':
            std::cin >> a;
            area = a * a;
            break;
        case 'r':
            std::cin >> a >> b;
            area = a * b;
            break;
        case 'c':
            std::cin >> r;
            area = PI * r * r;
            break;
        case 't':
            std::cin >> a >> h;
            area = 0.5 * a * h;
            break;
        default:
            std::cout << "Error: unknown figure" << std::endl;
            return 0;
    }

    // трик, ако ви се наложи да закръгляте след запетаята
    area = std::round(area * 100.0) / 100;

    std::cout << area << std::endl;
    return 0;
}

#include <iostream>

// Тази задача може да се реши и с ъглов наклон(ъгловите наклони на P1-P2 и P1-P3 съвпадат <=> P1-P2-P3 са колинеарни).
// Тук ще покажа интересно решение с линейна алгебра.
int main() {
    const double EPSILON = 0.0001;

    double x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    // Точките (x1, y1), (x2, y2) и (x3, y3) са колинеарни <=> триъгълникът, който образуват, има лице 0 <=> детерминантата:
    // | x1 y1 1 |
    // | x2 y2 1 | == 0
    // | x3 y3 1 |
    double cross = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);

    if (std::abs(cross) < EPSILON) {
        std::cout << "aligned\n";
    } else {
        std::cout << "wavy\n";
    }
    return 0;
}

#include <iostream>

int main() {
    unsigned int x1, y1, x2, y2, xSheep, ySheep;

    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cin >> xSheep >> ySheep;

    unsigned int distX, distY, distShip2;

    // ако овцата е вдясно от лидавата
    if (xSheep >= x2) {
        distX = xSheep - x2;
    } 
    // ако овцата е вляво от ливадата
    else if (xSheep <= x1) {
        distX = x1 - xSheep;
    }
    // ако овцата не е нито вляво, нито вдясно от ливадата
    else distX = 0;

    // ако овцата е нагоре от ливадата
    if (ySheep >= y2) {
        distY = ySheep - y2;
    } 
    // ако овцата е надолу от ливадата
    else if (ySheep <= y1) {
        distY = y1 - ySheep;
    }
    // ако овцата не е нито нагоре, нито надолу от ливадата
    else distY = 0;

    // c^2 = a^2 + b^2
    distShip2 = distX * distX + distY * distY;

    std::cout << distShip2 << std::endl;

    return 0;
}

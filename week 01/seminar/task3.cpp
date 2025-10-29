/*
Да се въведат две положителни числа а и r. Да се изведе лицето и обиколката на:
    квадрат със страна а;
    кръг с радиус r;
    равностранен триъгълник със страна а.
Нека за целите на задачата константите се закръглят до 4 знака след десетичната запетайка, съответно:

π = 3.1415
sqr3 = 1.7320 
*/

#include <iostream>

int main() {
    double a, r;
    const double PI = 3.1415, SQR3 = 1.7320;

    std::cin >> a >> r;

    double squareS = a * a, squareP = 4 * a;
    double circleS = PI * r * r, circleP = 2 * PI * r;
    double triangleS = (a * a * SQR3) / 4, triangleP = 3 * a;

    std::cout << "Square: P = " << squareP << ", S = " << squareS << std::endl;
    std::cout << "Circle: P = " << circleP << ", S = " << circleS << std::endl;
    std::cout << "Triangle: P = " << triangleP << ", S = " << triangleS << std::endl;

    return 0;
}
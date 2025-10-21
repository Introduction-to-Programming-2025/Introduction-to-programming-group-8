#include <iostream>

int main() {
    int a11, a12, a13;
    int a21, a22, a23;
    int a31, a32, a33;

    std::cin >> a11 >> a12 >> a13;
    std::cin >> a21 >> a22 >> a23;
    std::cin >> a31 >> a32 >> a33;

    // сума по редове
    int sumRow1 = a11 + a12 + a13;
    int sumRow2 = a21 + a22 + a23;
    int sumRow3 = a31 + a32 + a33;

    // сума по колони
    int sumCol1 = a11 + a21 + a31;
    int sumCol2 = a12 + a22 + a32;
    int sumCol3 = a13 + a23 + a33;

    // сума по диагонали
    int sumDiag1 = a11 + a22 + a33;
    int sumDiag2 = a13 + a22 + a31;

    bool isMagic = sumRow1 == sumRow2 &&
        sumRow2 == sumRow3 &&
        sumRow3 == sumCol1 &&
        sumCol1 == sumCol2 &&
        sumCol2 == sumCol3 &&
        sumCol3 == sumDiag1 &&
        sumDiag1 == sumDiag2;

    std::cout << (isMagic ? "" : "not ") << "magic square" << std::endl;

    return 0;
}
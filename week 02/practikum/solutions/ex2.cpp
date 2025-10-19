#include <iostream>

int main() {
    double a, b;
    long long aWhole, bWhole;
    char op;

    std:: cout << "op: ";
    std:: cin >> op;

    switch(op) {
        case '+':
        case '-':
        case '*':
        case '/':
            std::cout << "Insert real numbers a and b:";
            std::cin >> a >> b;
        break;

        case '%':
            std::cout << "Insert whole numbers a and b:";
            std::cin >> aWhole >> bWhole;
        break;
        default:
            std::cout << "Error: unknown operator\n";
            return -1;
    }

    switch (op) {
        case '+':
            std::cout << (a + b) << '\n';
            break;
        case '-':
            std::cout << (a - b) << '\n';
            break;
        case '*':
            std::cout << (a * b) << '\n';
            break;
        case '/':
            if (b == 0.0) {
                std::cout << "Error: division by zero\n";
            } else {
                std::cout << (a / b) << '\n';
            }
            break;
        case '%':
            if (bWhole == 0) {
                std::cout << "Error: modulo by zero\n";
            } else {
                std::cout << (aWhole % bWhole) << '\n';
            }
            break;
        default:
            std::cout << "Error: unknown operator\n";
    }
    return 0;
}

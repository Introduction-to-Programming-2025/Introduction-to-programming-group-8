#include <iostream>

void on(const int& n);
void off(const int& n);

void on(const int& n) {
    if (n <= 0) {
        return;
    }

    on(n - 1);
    off(n - 2);

    std::cout << "+" << n << std::endl;

    on(n - 2);
}

void off(const int& n) {
    if (n <= 0) {
        return;
    }

    on(n - 1);
    off(n - 2);

    std::cout << "-" << n << std::endl;

    off(n - 1);
}

int main() {
    int n;
    std::cin >> n;

    on(n);

    return 0;
}
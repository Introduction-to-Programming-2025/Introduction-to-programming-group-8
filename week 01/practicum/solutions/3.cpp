#include <iostream>

int main() {
    int a = 0, b = 0;

    std::cin >> a >> b;

    int temp = a;
    a = b;
    b = temp;

    std::cout << a << " " << b << std::endl;
    
    return 0;
}

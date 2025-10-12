#include <iostream>

int main() {
    double kelvins = 0;

    std::cin >> kelvins;

    double celsius = kelvins - 273.15;
    double fahrenheit = celsius * 1.8 + 32.0;

    std::cout << celsius << "C" << std::endl;
    std::cout << fahrenheit << "F" << std::endl;
    
    return 0;
}

#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;

    if (n > 777) {
        std::cout << "Error: expected an octal in range 000..777\n";
        return 0;
    }

    unsigned others =  n % 10;
    unsigned groups = (n / 10)  % 10;
    unsigned owners = (n / 100) % 10;

    if (owners > 7 || groups > 7 || others > 7) {
        std::cout << "Error: digits must be in [0..7]\n";
        return 0;
    }

    // & е побитов оператор - полезен, когато искаме да работи с битове
    // вмоментa го ползваме (като маска), за да взeмем конкретен бит
    std::cout << ((owners & 4) ? 'r' : '-') << ((owners & 2) ? 'w' : '-') << ((owners & 1) ? 'x' : '-') << ' ';
    std::cout << ((groups & 4) ? 'r' : '-') << ((groups & 2) ? 'w' : '-') << ((groups & 1) ? 'x' : '-') << ' ';
    std::cout << ((others & 4) ? 'r' : '-') << ((others & 2) ? 'w' : '-') << ((others & 1) ? 'x' : '-');
    return 0;
}

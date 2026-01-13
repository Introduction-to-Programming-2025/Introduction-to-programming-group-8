#include <iostream>

// намира възможните начини за образуване на сума M
int findSum(int m, size_t n, unsigned* coins, size_t currentIndex = 0) {
    // ако M е по-малко от 0, то това не е възможно
    if (m < 0) {
        return 0;
    }

    // ако M е 0, съществува точно 1 начин
    if (m == 0) {
        return 1;
    }

    size_t sum = 0;

    // обхождането продължава от последния разгледан индекс на монета с цел избягване на повторно броене *
    for (size_t i = currentIndex; i < n; ++i) {
        sum += findSum(m - coins[i], n, coins, i);
    }

    return sum;
}

int main() {
    size_t m, n;
    std::cin >> m >> n;

    unsigned* coins = new unsigned[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> coins[i];
    }

    std::cout << findSum(m, n, coins) << std::endl;

    delete[] coins;

    return 0;
}

/*
* - нека се разгледа следния малък пример:
3 3
1 3 2

За опростяване на илюстрацията няма да се разглеждат coins[x] > m', където m' е текущата търсена сума
Ако не се прескача текущия индекс:
coins[0] = 1: sum(3) -> sum(2)
    coins[0] = 1: sum(2) -> sum(1)
        coins[0] = 1: sum(1) -> 1
    coins[2] = 2: sum(2) -> 1
coins[1] = 3: sum(3) -> 1
coins[2] = 2: sum(3) -> sum(1)
    coins[0] = 1: sum(1) -> 1

Така излиза, че сума 3 може да се изплати по 4 начина:
1 + 1 + 1
1 + 2
2 + 1
3

Това не е коректно, понеже 1 + 2 == 2 + 1, поради неразличимостта на монетите.

Ако текушият индекс се взима предвид:
coins[0] = 1: sum(3) -> sum(2)
    coins[0] = 1: sum(2) -> sum(1)
        coins[0] = 1: sum(1) -> 1
    coins[2] = 2: sum(2) -> 1
coins[1] = 3: sum(3) -> 1
coins[2] = 2: sum(3) -> sum(1)
    coins[2] = 2: sum(1) -> 0

Получават се точно 3 начина за образуване на сума 3:
1 + 1 + 1
1 + 2
3

*/
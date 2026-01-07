#include <iostream>

const unsigned int GOOD = 42, BAD = 81;

bool checkKid(unsigned int kid, const unsigned int goodOrBad) {
    while (kid >= 100) { 
        if (kid % 100 == goodOrBad) {
            return true;
        }

        kid /= 10;
    }

    return kid == goodOrBad;
}

bool isBoy(unsigned int kid) {
    return kid % 2;
}

void filterBad(unsigned int* kids, size_t &size) {
    // прескачат се всички лоши деца в края на редицата
    while (checkKid(kids[size - 1], BAD)) {
        size--;
    }

    for (size_t i = 0; i < size; ++i) {
        // ако дете е лошо
        if (checkKid(kids[i], BAD)) {
            // се изпраща в края на редицата
            std::swap(kids[i], kids[size - 1]);

            // и размерът се намаля
            size--;
        }
    }
}

void sortGood(unsigned int* kids, size_t size) {
    // модификация на сортиране с пряка селекция
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if(checkKid(kids[j], GOOD) && !checkKid(kids[i], GOOD)) {
                std::swap(kids[j], kids[i]);
            }
        }
    }
}

int main() {

    size_t n;
    unsigned int girlsPresents, boysPresents;
    std::cin >> n >> girlsPresents >> boysPresents;

    unsigned* kids = new unsigned int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> kids[i];
    }

    filterBad(kids, n);
    sortGood(kids, n);

    unsigned int girlsPresentsToGive = girlsPresents, boysPresentsToGive = boysPresents;

    for (size_t i = 0; i < n; ++i) {
        if (isBoy(kids[i])) {
            if (boysPresentsToGive > 0) boysPresentsToGive --;
        }
        else {
            if (girlsPresentsToGive > 0) girlsPresentsToGive --;
        }
    }

    std::cout << boysPresents - boysPresentsToGive << " " << girlsPresents - girlsPresentsToGive << std::endl;

    delete[] kids;

    return 0;
}

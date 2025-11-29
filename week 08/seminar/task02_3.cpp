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

void addElement(unsigned int kid, unsigned int* &kids) {
    unsigned int* temp = new unsigned int[kids[0] + 1];

    for (size_t i = 0; i < kids[0]; ++i) {
        temp[i] = kids[i];
    }

    temp[kids[0]] = kid;

    delete[] kids;
    kids = temp;
    kids[0]++;
}

void filter(unsigned int* kids, size_t size, unsigned int**& classified) {
    for (size_t i = 0; i < size; ++i) {
        if (checkKid(kids[i], GOOD)) {
            addElement(kids[i], classified[0]);
        }
        else if (checkKid(kids[i], BAD)) {
            addElement(kids[i], classified[2]);
        }
        else {
            addElement(kids[i], classified[1]);
        }
    }
}

int main() {
    size_t n;
    unsigned int girlsPresents, boysPresents;
    std::cin >> n >> girlsPresents >> boysPresents;

    unsigned int* kids = new unsigned int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> kids[i];
    }

    unsigned int** kidsClassified = new unsigned int*[3];

    for (size_t i = 0; i < 3; ++i) {
        // в първия елемент на всеки ред ще се пази размера му
        kidsClassified[i] = new unsigned int[1];
        kidsClassified[i][0] = 0;
    }

    filter(kids, n, kidsClassified);

    
    unsigned int girlsPresentsToGive = girlsPresents, boysPresentsToGive = boysPresents;

    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 1; j < kidsClassified[i][0]; ++j) {
        if (isBoy(kidsClassified[i][j])) {
                if (boysPresentsToGive > 0) boysPresentsToGive --;
            }
            else {
                if (girlsPresentsToGive > 0) girlsPresentsToGive --;
            }
        }
    }

    std::cout << boysPresents - boysPresentsToGive << " " << girlsPresents - girlsPresentsToGive << std::endl;

    for (size_t i = 0; i < 3; ++i) {
        delete[] kidsClassified[i];
    }
    delete[] kidsClassified;

    delete[] kids;

    return 0;
}

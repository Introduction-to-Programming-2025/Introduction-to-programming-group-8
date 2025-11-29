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

void addElement(unsigned int kid, unsigned int* &kids, size_t &size) {
    unsigned int* temp = new unsigned int[size + 1];

    for (size_t i = 0; i < size; ++i) {
        temp[i] = kids[i];
    }

    temp[size] = kid;

    delete[] kids;
    kids = temp;
    size ++;
}

void populateGoodKids(
    unsigned int* kids, size_t size, 
    unsigned int* &goodKids, size_t &goodSize
) {
    for (size_t i = 0; i < size; ++i) {
        if(checkKid(kids[i], GOOD)) {
            addElement(kids[i], goodKids, goodSize);
        } 
    } 
}

void populateNotBadKids(
    unsigned int* kids, size_t size, 
    unsigned int* &notBadKids, size_t &notBadSize
) {
    for (size_t i = 0; i < size; ++i) {
        if(!checkKid(kids[i], BAD) && !checkKid(kids[i], GOOD)) {
            addElement(kids[i], notBadKids, notBadSize);
        } 
    } 
}

bool isBoy(unsigned int kid) {
    return kid % 2;
}

int main() {

    size_t n;
    unsigned int girlsPresents, boysPresents;
    std::cin >> n >> girlsPresents >> boysPresents;

    unsigned int* kids = new unsigned int[n];

    for (size_t i = 0; i < n; ++i) {
        std::cin >> kids[i];
    }

    size_t goodKidsSize = 0, notBadKidsSize = 0;
    unsigned int *goodKids = nullptr, *notBadKids = nullptr;

    populateGoodKids(kids, n, goodKids, goodKidsSize);
    populateNotBadKids(kids, n, notBadKids, notBadKidsSize);

    unsigned int girlsPresentsToGive = girlsPresents, boysPresentsToGive = boysPresents;

    for (size_t i = 0; i < goodKidsSize; ++i) {
        if (isBoy(goodKids[i])) {
            if (boysPresentsToGive > 0) boysPresentsToGive --;
        }
        else {
            if (girlsPresentsToGive > 0) girlsPresentsToGive --;
        }
    }

    for (size_t i = 0; i < notBadKidsSize; ++i) {
        if (isBoy(notBadKids[i])) {
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

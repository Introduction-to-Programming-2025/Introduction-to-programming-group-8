#include <iostream>
#include <cmath>

int main() {
    const double EPSILON = 0.0001;

    double referenceValue, candidate1, candidate2, candidate3;
    std::cin >> referenceValue >> candidate1 >> candidate2 >> candidate3;

    double distance1 = std::abs(candidate1 - referenceValue);
    double distance2 = std::abs(candidate2 - referenceValue);
    double distance3 = std::abs(candidate3 - referenceValue);

    double minDistance = distance1;
    if (distance2 + EPSILON < minDistance) {
        minDistance = distance2;
    }
    if (distance3 + EPSILON < minDistance) {
        minDistance = distance3;
    }

    bool isC1Closest = (std::abs(distance1 - minDistance) < EPSILON);
    bool isC2Closest = (std::abs(distance2 - minDistance) < EPSILON);
    bool isC3Closest = (std::abs(distance3 - minDistance) < EPSILON);

    int closestCount = (isC1Closest ? 1 : 0) + (isC2Closest ? 1 : 0) + (isC3Closest ? 1 : 0);

    if (closestCount == 1) {
        std::cout << "Closest is ";
        if (isC1Closest) {
            std::cout << "candidate1";
        } else if (isC2Closest) {
            std::cout << "candidate2";
        } else {
            std::cout << "candidate3";
        }
        std::cout  << " with distance " << minDistance << std::endl;
    } else {
        std::cout << "Multiple candidates are equally close at distance " << minDistance << ":" << std::endl;
        if (isC1Closest) {
            std::cout << "candidate1" << std::endl;
        }
        if (isC2Closest) { 
            std::cout << "candidate2" << std::endl;
        }
        if (isC3Closest) { 
            std::cout << "candidate3" << std::endl;
        }
    }
    return 0;
}

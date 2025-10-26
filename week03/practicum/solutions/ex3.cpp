#include <iostream>

int main(){
    int m;
    std::cin >> m;

    int found = 0;
    unsigned long long x = 10;

    while (found < m){
        unsigned long long temp = x, result = 0;

        while(temp > 0) {
            result = result * 10 + (temp % 10);
            temp /= 10;
        }

        if(result == x) {
            std::cout << x << " ";
            found++;
        }
        x++;
    }
    return 0;
}

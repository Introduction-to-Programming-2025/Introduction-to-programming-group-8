#include <iostream>

int main(){
    unsigned long long n; 
    std::cin >> n;

    if (n == 0){
        std::cout << 0;
        return 0;
    }

    unsigned long long powerOfTwo = 1;
    while (powerOfTwo <= n/2) {
        powerOfTwo *= 2;
    }

    bool started = false;

    while (powerOfTwo > 0) {
        if(n >= powerOfTwo){
            std::cout << 1;
            n -= powerOfTwo;
            started = true;
        }
        else if(started){
            std::cout << 0;
        }
        
        powerOfTwo /= 2;
    }

    return 0;
}

#include <iostream>

int main(){
    unsigned long long n; 
    std::cin >> n;

    unsigned long long reversed = 0, temp = n;

    while(temp > 0){ 
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }

    int digs = (n == 0) ? 1 : 0;
    temp = n;
    
    if(n == 0) {
        digs = 1;
    }

    while(temp > 0){ 
        digs++;
        temp /= 10; 
    }

    unsigned long long powerOfTen = 1;
    for(int i = 0; i < digs; i++) {
        powerOfTen *= 10;
    }

    std::cout << (reversed*powerOfTen + n);

    return 0;
}

#include <iostream>

int main(){
    long long start, end; 

    std::cin >> start >> end;

    if(start > end){ 
        long long t = start;
        start = end; 
        end = t;
    }

    for(long long n = start; n <= end; n++){
        bool prime = true;

        if(n < 2) {
            prime = false;
        } else if(n == 2 || n == 3) {
            prime = true;
        } else if(n % 2 == 0) {
            prime = false;
        } else {
            for (long long divisor = 3; divisor*divisor <= n; divisor += 2){
                if(n % divisor == 0){ 
                    prime = false; 
                    break;
                }
            }
        }

        if(prime) {
            std::cout << n << " ";
        }
    }
    return 0;
}

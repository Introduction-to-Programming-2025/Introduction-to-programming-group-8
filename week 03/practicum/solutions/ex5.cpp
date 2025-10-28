#include <iostream>

int main(){
    int n; 
    std::cin >> n;

    long long prev, cur;
    std::cin >> prev;

    unsigned long long max1 = 0, max2 = 0;

    for(int i = 1; i < n; i++){
        std::cin >> cur;
        unsigned long long d = cur >= prev ? cur - prev : prev - cur;
        
        if(d >= max1){
            max2 = max1;
            max1 = d;
        } else if(d > max2){
            max2 = d;
        }
        
        prev = cur;
    }

    std:: cout << max2;
    
    return 0;
}

#include <iostream>

int main(){
    long long start,end; 
    std::cin >> start >> end;

    if(start > end){ 
        long long temp = start; 
        start = end; 
        end = temp; 
    }

    for(long long x = start; x <= end; x++){
        long long sum = 0, temp = x;

        if(temp == 0){
            sum += 1;
        }

        while(temp > 0){
            int d = temp%10;

            long long factorial = 1;

            for(int i = 2; i <= d; i++) {
                factorial *= i;
            }

            sum += factorial;
            temp /= 10;
        }
        
        if(sum == x) {
            std::cout << x << " ";
        }
    }
    return 0;
}

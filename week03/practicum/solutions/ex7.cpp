#include <iostream>

int main(){
    unsigned long long first;
    std::cin >> first;

    if(first == 0){
        std::cout << 0;
        return 0;
    }

    unsigned long long built = first;
    unsigned long long lastInput = first;
    unsigned long long lastAppended = first;

    while(true){
        unsigned long long currentInput; 
        std:: cin >> currentInput;
        
        if(currentInput == 0) { 
            break;
        }

        if(currentInput > lastInput) {
            int digs = currentInput == 0 ? 1 : 0;

            unsigned long long temp = currentInput;

            while(temp > 0) {
                digs++; 
                temp /= 10;
            }
            
            unsigned long long powerOfTen = 1;
            
            for(int i = 0; i < digs; i++) {
                powerOfTen *= 10;
            }

            built = built*powerOfTen + currentInput;
            lastAppended = currentInput;
        } else if(currentInput < lastInput) {
            unsigned long long candidate = currentInput + (lastAppended / 2);

            if(candidate > lastInput){
                int digs = candidate == 0 ? 1 : 0;
                
                unsigned long long temp = candidate;
                
                while(temp > 0) {
                    digs++;
                    temp /= 10;
                }
                
                unsigned long long powerOfTen = 1;

                for(int i = 0; i < digs; i++) {
                    powerOfTen *= 10;
                }

                built = built*powerOfTen + candidate;
                lastAppended = candidate;
            }
        }
        lastInput = currentInput;
    }

    std::cout << built;
    return 0;
}

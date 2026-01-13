#include <iostream>
#include <cstring>

const char OPEN = '(', CLOSE = ')';
const size_t STRLEN = 128;

void extractSubexpression(const char expr[], char output[]) {
    int openedBraces = 1;

    for (size_t i = 1; i < strlen(expr); ++i) {
        if (expr[i] == OPEN) openedBraces ++;
        else if (expr[i] == CLOSE) {
            openedBraces --;

            if (openedBraces == 0) {
                strncpy(output, expr + 1, i - 1);
                output[i - 1] = '\0';

                return;
            }
        }
        
    }

    strcpy(output, expr);
}

int calculate(int a, char op, int b) {
    switch(op) {
        case '+': return a + b;
        case '*': return a * b;
    }
}

int calculate(const char expr[]) {
    char subexpr[STRLEN];

    int result = 0, x = 0;
    char operation = '+';
    
    size_t index = 0;
    while (index < strlen(expr)) {
        if (expr[index] == OPEN) {
            extractSubexpression(expr + index, subexpr);
            x = calculate(subexpr);
            index += strlen(subexpr) + 1;
        }
        else if (expr[index] >= '0' && expr[index] <= '9') {
            x = x * 10 + expr[index] - '0';
        }
        else {
            result = calculate(result, operation, x);
            operation = expr[index];
            x = 0;
        }

        ++index;
    }

    result = calculate(result, operation, x);

    return result;
}

int main() {    
    char expr[STRLEN];
    std::cin.getline(expr, STRLEN - 1);

    std::cout << calculate(expr) << std::endl;

    return 0;
}

#include <iostream>

int main() {
    unsigned year = 0;
    std::cin >> year;

    bool isLeap = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    
    // това се нарича тернарен оператор. Пише се <условие> ? <израз, оценява се при истина> : <израз, оценява се при лъжа>
    std::cout << (isLeap ? "leap\n" : "ordinary\n");

    return 0;
}

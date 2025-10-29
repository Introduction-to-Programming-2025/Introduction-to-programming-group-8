#include <iostream>

int main() {
    const unsigned short FEBRUARY = 2;
    const unsigned short JULY = 7;

    unsigned short day, month, year;

    std::cin >> day >> month >> year;

    // годината е високосна, когато се дели на 4, но не на 100
    // или се дели на 400
    bool isLeapYear = (!(year % 4) && (year % 100)) || !(year % 400);

    bool has31days = month <= JULY ? month % 2 : !(month % 2);

    short int maxMonthDays = (has31days ? 31 : 30);
    if (month == FEBRUARY) {
        maxMonthDays = (isLeapYear ? 29 : 28); 
    }

    if (month > 12 || day > maxMonthDays) {
        std::cout << "Invalid day!" << std::endl;

        return 0;
    }

    day ++;

    if (day > maxMonthDays) {
        day = 1;
        month ++;

        if (month == 13) {
            month = 1;
            year ++;
        }
    }

    std::cout << day << "." << month << "." << year << std::endl;

    return 0;
}
#include <iostream>

int СalcNumberOfDays(int month, int year)
{
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
            break;
        case 2:
            if ((year % 400 == 0 || year % 100 != 0) && year % 4 == 0) {
                return 29;
            } else {
                return 28;
            }
            break;
    }
    return 30;
}

int main()
{
    int month, year;
    std::cin >> month >> year;
    std::cout << СalcNumberOfDays(month, year) << std::endl;
}
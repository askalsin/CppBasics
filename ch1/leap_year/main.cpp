#include <iostream>
#include <string>

std::string IsLeapYear(int year)
{
    if (year % 400 == 0) {
        return "YES";
    } else if (year % 100 == 0) {
        return "NO";
    } else if (year % 4 == 0) {
        return "YES";
    }

    return "NO";
}

int main()
{
    int year;
    std::cin >> year;
    std::cout << IsLeapYear(year) << std::endl;
}
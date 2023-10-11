#include <iostream>

void PrintCalendar(int weekday, int daysInMonth)
{
    int dayOfWeek = weekday;

    for (int i = 1; i < weekday; ++i) {
        std::cout << "   ";
    }

    for (int day = 1; day <= daysInMonth; ++day) {
        if (day < 10) {
            std::cout << " ";
        }

        std::cout << day;

        if (dayOfWeek == 7) {
            std::cout << "\n";
            dayOfWeek = 1;
        } else {
            std::cout << " ";
            dayOfWeek += 1;
        }
    }

    if (dayOfWeek != 1) {
        std::cout << "\n";
    }
}

int main()
{
    int weekday, daysInMonth;
    std::cin >> weekday >> daysInMonth;
    PrintCalendar(weekday, daysInMonth);
}
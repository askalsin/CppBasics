#include <algorithm>
#include <iostream>
#include <stdexcept>

class Logger {
private:
    static int counter;
    const int id;

public:
    Logger() : id(++counter)
    {
        std::cout << "Logger(): " << id << "\n";
    }

    Logger(const Logger& other) : id(++counter)
    {
        std::cout << "Logger(const Logger&): " << id << " " << other.id << "\n";
    }

    Logger(Logger&& other) : id(++counter)
    {
        std::cout << "Logger(Logger&&): " << id << " " << other.id << "\n";
    }

    Logger& operator=(const Logger& other)
    {
        std::cout << "Logger& operator = (const Logger&): " << id << " "
                  << other.id << "\n";
        return *this;
    }

    Logger& operator=(Logger&& other)
    {
        std::cout << "Logger& operator = (Logger&&): " << id << " " << other.id
                  << "\n";
        return *this;
    }

    ~Logger()
    {
        std::cout << "~Logger(): " << id << "\n";
    }
};

int Logger::counter = 0;

// #include "logger.h"

int main()
{
    Logger x1;
    Logger* x2 = new Logger;
    Logger* x3 = new Logger;
    delete x2;
    delete x3;
}
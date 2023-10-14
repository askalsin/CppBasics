#include <iostream>
#include <string>

#include "address.h"

int main()
{
    std::string line;
    while (getline(std::cin, line)) {
        try {
            Address address;
            Parse(line, &address);
            Unify(&address);
            std::cout << Format(address) << "\n";
        } catch (...) {
            std::cout << "exception\n";
        }
    }
}
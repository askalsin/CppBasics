#include <iostream>
#include <string>

std::string IsCorrectPassword(std::string pass)
{
    if (pass.size() < 8 || pass.size() > 14) {
        return "NO";
    }

    int upper = 0, lower = 0, digit = 0, other = 0;

    for (const char &c : pass) {
        if (c < 33 || c > 126) {
            return "NO";
        }
        if ('A' <= c && c <= 'Z') {
            upper = 1;
        } else if ('a' <= c && c <= 'z') {
            lower = 1;
        } else if ('0' <= c && c <= '9') {
            digit = 1;
        } else {
            other = 1;
        }
    }

    return upper + lower + digit + other >= 3 ? "YES" : "NO";
}

int main()
{
    std::string pass;
    std::cin >> pass;
    std::cout << IsCorrectPassword(pass) << std::endl;
}
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>

int main()
{
    std::string str = "";

    std::string word;
    while (std::cin >> word) {
        str += word;
    }

    std::string rstr = str;
    std::reverse(rstr.begin(), rstr.end());

    if (str == rstr) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> strs;
    std::string str;

    while (std::getline(std::cin, str)) {
        strs.push_back(str);
    }

    std::sort(strs.rbegin(), strs.rend());

    for (const auto &s : strs) {
        std::cout << s << std::endl;
    }
}
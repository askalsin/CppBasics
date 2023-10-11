#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main()
{
    std::string word;
    std::cin >> word;
    std::unordered_set<char> latters(word.begin(), word.end());

    std::unordered_set<char> temp;
    while (std::cin >> word) {
        for (const auto& c : word) {
            if (latters.find(c) != latters.end()) {
                temp.insert(c);
            }
        }
        latters = temp;
        temp.clear();
    }

    std::vector<char> sortLatters(latters.begin(), latters.end());
    std::sort(sortLatters.begin(), sortLatters.end());

    for (const auto& c : sortLatters) {
        std::cout << c;
    }
    std::cout << "\n";
}
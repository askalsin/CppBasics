#include <cstddef>
#include <iostream>
#include <map>
#include <set>

int main()
{
    size_t n;
    std::cin >> n;

    std::map<size_t, std::set<std::string>> book;
    std::string word;
    size_t page;

    for (size_t i = 0; i != n; ++i) {
        std::cin >> word >> page;
        book[page].insert(word);
    }

    for (const auto& [key, val] : book) {
        std::cout << key;
        for (const auto& word : val) {
            std::cout << " " << word;
        }
        std::cout << "\n";
    }
}
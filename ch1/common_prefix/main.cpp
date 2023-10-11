#include <iostream>
#include <string>
#include <vector>

std::string CommonPrefix(const std::vector<std::string>& words)
{
    if (words.empty()) {
        return "";
    }

    size_t minIndex = words[0].size();
    for (size_t i = 1; i != words.size(); ++i) {
        for (size_t j = 0; j != words[0].size(); ++j) {
            if (!(words[0][j] == words[i][j])) {
                if (minIndex > j) {
                    minIndex = j;
                }
                break;
            }
        }
    }

    return words[0].substr(0, minIndex);
}

int main()
{
    std::vector<std::string> words = {"apple", "apricot", "application",
                                      "applllllllll"};
    std::cout << CommonPrefix(words) << std::endl;

    words = {"aapple", "aaaparicot", "aaapppplication"};
    std::cout << CommonPrefix(words) << std::endl;

    words.clear();
    std::cout << CommonPrefix(words) << std::endl;
}
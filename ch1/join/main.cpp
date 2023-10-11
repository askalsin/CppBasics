#include <iostream>
#include <string>
#include <vector>

std::string Join(const std::vector<std::string>& tokens, char delimiter)
{
    std::string result;

    for (size_t i = 0; i != tokens.size(); ++i) {
        result += tokens[i];
        if (i != tokens.size() - 1) {
            result += delimiter;
        }
    }

    return result;
}

int main()
{
    std::vector<std::string> tokens;
    char delimiter = '_';
    std::cout << Join(tokens, delimiter) << std::endl;
}
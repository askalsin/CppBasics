#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> MySplit(const std::string& str, char delimiter)
{
    if (str.empty()) {
        return {};
    }

    std::vector<std::string> result;
    std::string substr;

    for (const auto& s : str) {
        if (s == delimiter) {
            result.push_back(substr);
            substr.clear();
            continue;
        }
        substr.push_back(s);
    }
    if (!substr.empty()) {
        result.push_back(substr);
    }

    if (str.back() == delimiter) {
        result.push_back("");
    }

    return result;
}

std::vector<std::string> Split(const std::string& str, char delimiter)
{
    std::vector<std::string> result;
    size_t i = 0;
    for (size_t j = 0; j != str.size(); ++j) {
        if (str[j] == delimiter) {
            result.push_back(str.substr(i, j - i));
            i = j + 1;
        }
    }
    result.push_back(str.substr(i));
    return result;
}

int main()
{
    std::string str = "-13-24--08-11-2014-";
    char delimiter = '-';

    std::vector<std::string> strSplit = Split(str, delimiter);
    for (const auto& s : strSplit) {
        std::cout << s << std::endl;
    }
}
#include <iostream>
#include <iterator>
#include <list>
#include <string>

int main()
{
    std::list<std::string> text;
    std::string str;
    while (std::getline(std::cin, str)) {
        if (str.empty()) {
            break;
        }
        text.push_back(str);
    }

    auto iter = text.begin();
    std::string bufer;
    while (std::cin >> str) {
        if (str == "Down" && iter != text.end()) {
            ++iter;
        } else if (str == "Up" && iter != text.begin()) {
            --iter;
        } else if (str == "Ctrl+X" && iter != text.end()) {
            bufer = std::move(*iter);
            iter = text.erase(iter);
        } else if (str == "Ctrl+V" && !bufer.empty()) {
            text.insert(iter, bufer);
        }
    }

    for (const auto& str : text) {
        std::cout << str << "\n";
    }
}

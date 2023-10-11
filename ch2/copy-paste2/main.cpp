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
    std::list<std::string> buffer;
    bool shiftPressed = false;
    int shiftOffset = 0;
    auto shift = text.begin();

    while (std::cin >> str) {
        if (str == "Shift") {
            shiftPressed = true;
        } else if (str == "Down" && iter != text.end()) {
            ++iter;
            if (!shiftPressed) {
                shift = iter;
            } else {
                ++shiftOffset;
            }
        } else if (str == "Up" && iter != text.begin()) {
            --iter;
            if (!shiftPressed) {
                shift = iter;
            } else {
                --shiftOffset;
            }
        } else if (str == "Ctrl+X" && iter != text.end()) {
            buffer.clear();

            if (shift == iter) {
                auto toSplice = iter;
                iter = std::next(iter);
                buffer.splice(buffer.begin(), text, toSplice);
            } else if (shiftOffset < 0) {
                buffer.splice(buffer.begin(), text, iter, shift);
                iter = shift;
            } else {
                buffer.splice(buffer.begin(), text, shift, iter);
            }

            shiftPressed = false;
            shift = iter;
            shiftOffset = 0;
        } else if (str == "Ctrl+V" && !buffer.empty()) {
            if (shiftOffset < 0) {
                iter = text.erase(iter, shift);
            } else if (shiftOffset > 0) {
                iter = text.erase(shift, iter);
            }

            text.insert(iter, buffer.begin(), buffer.end());

            shiftPressed = false;
            shift = iter;
            shiftOffset = 0;
        }
    }

    for (const auto& str : text) {
        std::cout << str << "\n";
    }
}

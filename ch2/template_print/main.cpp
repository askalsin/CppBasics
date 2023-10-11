#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename T>
void Print(const T& data, const std::string& delimiter)
{
    bool first = true;

    for (const auto& i : data) {
        if (!first) {
            std::cout << delimiter;
        } else {
            first = false;
        }
        std::cout << i;
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> data = {1, 2, 3};
    Print(data, ", ");

    std::list<int> l = {0, 1, 2, 3, 4};
    Print(l, ", ");
}
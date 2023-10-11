#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> numbers;
    int number;

    std::string result;
    while (std::cin >> number) {
        if (!numbers.insert(number).second) {
            result += "YES\n";
        } else {
            result += "NO\n";
        }
    }

    std::cout << result;
}
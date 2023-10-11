#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::string command;
    std::priority_queue<int> data;

    std::string result;
    while (std::cin >> command) {
        if (command == "ADD") {
            int n;
            std::cin >> n;
            data.push(n);
        } else if (command == "CLEAR") {
            data = std::priority_queue<int>();
        } else if (command == "EXTRACT" && !data.empty()) {
            result += std::to_string(data.top()) + "\n";
            data.pop();
        } else {
            result += "CANNOT\n";
        }
    }

    std::cout << result;
}
#include <iostream>
#include <stack>
#include <string>

std::string isValid(std::string& data)
{
    std::stack<char> brackets;

    for (const auto& c : data) {
        if (c == '{' || c == '[' || c == '(') {
            brackets.push(c);
        } else {
            if (brackets.empty()) {
                return "NO";
            }

            char top = brackets.top();
            if ((top == '{' && c == '}') || (top == '[' && c == ']') ||
                (top == '(' && c == ')')) {
                brackets.pop();
            } else {
                return "NO";
            }
        }
    }

    return brackets.empty() ? "YES" : "NO";
}

int main()
{
    std::string data;
    std::cin >> data;
    std::cout << isValid(data) << "\n";
}
#include <iostream>
#include <queue>
#include <set>

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::queue<int> numbers;
    std::multiset<int> window;

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        numbers.push(x);
        window.insert(x);
        if (i >= k) {
            std::cout << *window.begin() << "\n";
            auto iter = window.find(numbers.front());
            window.erase(iter);
            numbers.pop();
        }
    }
}
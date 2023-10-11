#include <cstddef>
#include <deque>
#include <iostream>
#include <string>

void MakeTrain()
{
    std::deque<size_t> train;
    std::string command;
    size_t n;
    while (std::cin >> command >> n) {
        if (command == "+left") {
            train.push_front(n);
        } else if (command == "+right") {
            train.push_back(n);
        } else if (command == "-left") {
            n = std::min(n, train.size());
            train.erase(train.begin(), train.begin() + n);
        } else if (command == "-right") {
            n = std::min(n, train.size());
            train.erase(train.end() - n, train.end());
        }
    }

    for (const auto& i : train) {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}

int main()
{
    MakeTrain();
}
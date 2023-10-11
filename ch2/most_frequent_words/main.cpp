#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

int main()
{
    size_t k;
    std::cin >> k;

    std::unordered_map<std::string, size_t> words;
    std::string word;
    while (std::cin >> word) {
        ++words[word];
    }

    std::priority_queue<std::pair<int, std::string>> pq;

    for (const auto& [word, count] : words) {
        pq.push({-count, word});
        if (pq.size() > k) {
            pq.pop();
        }
    }

    std::vector<std::pair<int, std::string>> top;
    top.reserve(k);

    while (!pq.empty()) {
        const auto& [count, word] = pq.top();
        top.push_back({-count, word});
        pq.pop();
    }

    std::reverse(top.begin(), top.end());

    for (const auto& [count, word] : top) {
        std::cout << word << "\t" << count << "\n";
    }
}
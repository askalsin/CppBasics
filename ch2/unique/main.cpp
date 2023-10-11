#include <iostream>
#include <vector>

template <typename Iter>
Iter Unique(Iter first, Iter last)
{
    auto it1 = first;
    auto it2 = first;
    while (it2 != last) {
        if (it1 != it2) {
            *it1 = *it2;
        }
        ++it1;
        const auto& value = *it2;
        while (it2 != last && *it2 == value) {
            ++it2;
        }
    }
    return it1;
}

int main()
{
    std::vector<int> v = {1, 1, 2, 3, 3, 4, 5, 6};

    auto iter = Unique(v.begin(), v.end());

    for (const auto& i : v) {
        std::cout << i << ", ";
    }
}
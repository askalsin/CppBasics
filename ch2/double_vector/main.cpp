#include <iostream>
#include <vector>

template <typename T>
void Duplicate(std::vector<T>& v)
{
    size_t n = v.size();
    for (size_t i = 0; i != n; ++i) {
        v.push_back(v[i]);
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3};
    Duplicate(v);

    for (const auto& i : v) {
        std::cout << i << " ";
    }
}
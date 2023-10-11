#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int Approx(const std::vector<int>& v, int x)
{
    auto iter = std::lower_bound(v.begin(), v.end(), x);
    if (iter == v.end()) {
        return *std::prev(iter);
    } else if (iter == v.begin()) {
        return *iter;
    } else if (*iter == x) {
        return *iter;
    } else {
        int x1 = *std::prev(iter);
        int x2 = *iter;
        if (std::abs(x1 - x) <= std::abs(x2 - x)) {
            return x1;
        } else {
            return x2;
        }
    }
}

int main()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i != n; ++i) {
        std::cin >> v[i];
    }

    for (int i = 0; i != k; ++i) {
        int x;
        std::cin >> x;
        std::cout << Approx(v, x) << "\n";
    }
}

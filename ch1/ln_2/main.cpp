#include <cmath>
#include <iostream>

double ln2(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += std::pow(-1, i + 1) / static_cast<double>(i);
    }

    return sum;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << ln2(n) << std::endl;
}
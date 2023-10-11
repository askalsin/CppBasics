#include <iostream>
#include <string>

std::string IsRightTriangle(int a, int b, int c)
{
    if (!(a + b > c && a + c > b && c + b > a)) {
        return "UNDEFINED";
    }

    if (a * a + b * b == c * c || a * a + c * c == b * b ||
        c * c + b * b == a * a) {
        return "YES";
    }
    return "NO";
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << IsRightTriangle(a, b, c) << std::endl;
}
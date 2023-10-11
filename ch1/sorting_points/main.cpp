#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
    int x, y;
};

int main()
{
    size_t n;
    std::cin >> n;
    std::vector<Point> points(n);

    for (auto &point : points) {
        std::cin >> point.x >> point.y;
    }

    std::sort(points.begin(), points.end(),
              [](const Point &lp, const Point &rp) {
                  return lp.x * lp.x + lp.y * lp.y < rp.x * rp.x + rp.y * rp.y;
              });

    for (const auto &point : points) {
        std::cout << point.x << " " << point.y << std::endl;
    }
}
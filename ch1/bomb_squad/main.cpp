#include <iostream>
#include <vector>

int main()
{
    int m, n, k;
    std::cin >> m >> n >> k;

    std::vector<std::vector<char>> field(m, std::vector<char>(n, '0'));

    for (int i = 0; i != k; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        field[x][y] = '*';

        if (x - 1 >= 0 && y - 1 >= 0 && field[x - 1][y - 1] != '*') {
            ++field[x - 1][y - 1];
        }
        if (x - 1 >= 0 && field[x - 1][y] != '*') {
            ++field[x - 1][y];
        }
        if (x - 1 >= 0 && y + 1 < n && field[x - 1][y + 1] != '*') {
            ++field[x - 1][y + 1];
        }
        if (y + 1 < n && field[x][y + 1] != '*') {
            ++field[x][y + 1];
        }
        if (x + 1 < m && y + 1 < n && field[x + 1][y + 1] != '*') {
            ++field[x + 1][y + 1];
        }
        if (x + 1 < m && field[x + 1][y] != '*') {
            ++field[x + 1][y];
        }
        if (x + 1 < m && y - 1 >= 0 && field[x + 1][y - 1] != '*') {
            ++field[x + 1][y - 1];
        }
        if (y - 1 >= 0 && field[x][y - 1] != '*') {
            ++field[x][y - 1];
        }
    }

    for (int i = 0; i != m; ++i) {
        for (int j = 0; j != n; ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
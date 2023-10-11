#include <cmath>
#include <iostream>
#include <string>

// Мое решение
std::string MyIsCorrectQueenMove(short x1, short y1, short x2, short y2)
{
    if (x1 == x2 || y1 == y2) {
        return "YES";
    }

    for (short i = 1; i <= 8; ++i) {
        if (x2 == x1 + i && y2 == y1 - i) {
            return "YES";
        }
        if (x2 == x1 - i && y2 == y1 + i) {
            return "YES";
        }
        if (x2 == x1 - i && y2 == y1 - i) {
            return "YES";
        }
        if (x2 == x1 + i && y2 == y1 + i) {
            return "YES";
        }
    }
    return "NO";
}

std::string IsCorrectQueenMove(short x1, short y1, short x2, short y2)
{
    if (std::abs(x1 - x2) == abs(y1 - y2) || x1 == x2 || y1 == y2) {
        return "YES";
    }
    return "NO";
}

int main()
{
    short x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    std::cout << IsCorrectQueenMove(x1, y1, x2, y2) << std::endl;

    // std::string array[8][8];
    // for(short i = 0; i < 8; ++i) {
    //     for(short j = 0; j < 8; ++j) {
    //         array[i][j] = IsCorrectQueenMove(x1, y1, i+1, j+1);
    //     }
    // }
    // array[x1-1][y1-1] = "O";

    // for(short i = 0; i < 8; ++i) {
    //     for(short j = 0; j < 8; ++j) {
    //         std::cout << array[i][j] << "\t";
    //     }
    //     std::cout << std::endl;
    // }
}
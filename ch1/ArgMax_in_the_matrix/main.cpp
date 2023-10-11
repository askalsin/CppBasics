#include <iostream>
#include <utility>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(
    const std::vector<std::vector<int>>& matrix)
{
    int mx = matrix[0][0];
    std::pair<size_t, size_t> coordinates = {0, 0};

    for (size_t i = 0; i != matrix.size(); ++i) {
        for (size_t j = 0; j != matrix[0].size(); ++j) {
            if (mx < matrix[i][j]) {
                mx = matrix[i][j];
                coordinates = {i, j};
            }
        }
    }

    return coordinates;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {0, 3, 2, 4},
        {2, 3, 5, 5},
        {5, 1, 2, 3},
    };

    std::pair<size_t, size_t> coordinates = MatrixArgMax(matrix);
    std::cout << "X: " << coordinates.first << " Y: " << coordinates.second;
    std::cout << " is: " << matrix[coordinates.first][coordinates.second]
              << std::endl;
}
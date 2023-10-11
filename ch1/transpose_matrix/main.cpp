#include <cstddef>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(
    const std::vector<std::vector<int>>& matrix)
{
    const size_t m = matrix.size();
    const size_t n = matrix[0].size();
    std::vector<std::vector<int>> tMatrix(n, std::vector<int>(m));

    for (size_t i = 0; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            tMatrix[j][i] = matrix[i][j];
        }
    }

    return tMatrix;
}

int main()
{
    std::vector<std::vector<int>> matrix = {
        {2, 0, 5},
        {1, 4, 6},
    };

    std::vector<std::vector<int>> tMatrix = Transpose(matrix);

    for (size_t i = 0; i != tMatrix.size(); ++i) {
        for (size_t j = 0; j != tMatrix[0].size(); ++j) {
            std::cout << tMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
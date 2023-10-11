#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
class Table {
private:
    std::vector<std::vector<T>> data;

public:
    size_t GetRows() const
    {
        return data.size();
    }

    size_t GetColumns() const
    {
        if (data.empty()) {
            return 0;
        }

        return data[0].size();
    }

    Table(size_t rows, size_t columns)
    {
        resize(rows, columns);
    }

    const std::vector<T>& operator[](size_t i) const
    {
        return data[i];
    }

    std::vector<T>& operator[](size_t i)
    {
        return data[i];
    }

    void resize(size_t rows, size_t columns)
    {
        data.resize(rows);

        for (auto& row : data) {
            row.resize(columns);
        }
    }

    std::pair<size_t, size_t> size() const
    {
        return {GetRows(), GetColumns()};
    }
};

int main()
{
    Table<int> tb(4, 4);

    std::cout << "Rows: " << tb.GetRows() << "\n";
    std::cout << "Columns: " << tb.GetColumns() << "\n";

    tb[0][0] = 1;
    tb[1][1] = 1;
    tb[2][2] = 1;
    tb[3][3] = 1;
    std::cout << "tb[0][0]: " << tb[0][0] << "\n";
    std::cout << "tb[1][1]: " << tb[1][1] << "\n";
    std::cout << "tb[2][2]: " << tb[2][2] << "\n";
    std::cout << "tb[3][3]: " << tb[3][3] << "\n";

    tb.resize(3, 4);

    std::cout << "Rows: " << tb.GetRows() << "\n";
    std::cout << "Columns: " << tb.GetColumns() << "\n";

    std::cout << "tb[0][0]: " << tb[0][0] << "\n";
    std::cout << "tb[1][1]: " << tb[1][1] << "\n";
    std::cout << "tb[2][2]: " << tb[2][2] << "\n";

    auto sz = tb.size();
    std::cout << "Rows: " << sz.first << "\n";
}
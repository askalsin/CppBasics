#include <cstddef>
#include <cstdint>
#include <vector>

template <typename T>
class AdvancedVector : public std::vector<T> {
public:
    AdvancedVector() = default;

    template <typename Iter>
    AdvancedVector(Iter first, Iter last) : std::vector<T>(first, last)
    {
    }

    const T& operator[](std::int64_t i) const
    {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }

    T& operator[](std::int64_t i)
    {
        if (i < 0) {
            i += this->size();
        }
        return this->at(i);
    }
};

int main()
{
    AdvancedVector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(2);

    AdvancedVector<int> b = a;
}
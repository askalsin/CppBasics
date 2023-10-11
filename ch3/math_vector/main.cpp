#include <iostream>
#include <vector>

template <typename T>
class MathVector {
private:
    std::vector<T> data;

public:
    MathVector(size_t n)
    {
        data.resize(n);
    }

    template <typename Iter>
    MathVector(Iter first, Iter last)
    {
        while (first != last) {
            data.push_back(*first);
            first++;
        }
    }

    size_t Dimension() const
    {
        return data.size();
    }

    T& operator[](size_t i)
    {
        return data[i];
    }

    const T& operator[](size_t i) const
    {
        return data.at(i);
    }
};

// Output format: (1, 2, 3, 4, 5)
template <typename T>
std::ostream& operator<<(std::ostream& out, const MathVector<T>& v)
{
    out << '(';
    for (size_t i = 0; i != v.Dimension(); ++i) {
        if (i > 0) {
            out << ", ";
        }
        out << v[i];
    }
    out << ')';
    return out;
}

template <typename T>
MathVector<T>& operator*=(MathVector<T>& v, const T& scalar)
{
    for (size_t i = 0; i != v.Dimension(); ++i) {
        v[i] *= scalar;
    }
    return v;
}

template <typename T>
MathVector<T> operator*(const MathVector<T>& v, const T& scalar)
{
    auto tmp(v);
    tmp *= scalar;
    return tmp;
}

template <typename T>
MathVector<T>& operator+=(MathVector<T>& v1, const MathVector<T>& v2)
{
    for (size_t i = 0; i != v1.Dimension(); ++i) {
        v1[i] += v2[i];
    }
    return v1;
}

template <typename T>
MathVector<T> operator+(const MathVector<T>& v1, const MathVector<T>& v2)
{
    auto tmp(v1);
    tmp += v2;
    return tmp;
}

template <typename T>
MathVector<T> operator*(const T& scalar, const MathVector<T>& v)
{
    return v * scalar;
}

int main()
{
    std::vector<int> tmp = {1, 2, 3, 4, 5};
    MathVector<int> n1(5), n2(tmp.begin(), tmp.end());

    std::cout << "Dimention = " << n1.Dimension() << " " << n1 << "\n";
    std::cout << "Dimention = " << n2.Dimension() << " " << n2 << "\n";

    n1 += n2;
    std::cout << "Dimention = " << n1.Dimension() << " " << n1 << "\n";

    n1 = n1 + n2;
    std::cout << "Dimention = " << n1.Dimension() << " " << n1 << "\n";
    
    n2 *= 2;
    std::cout << "Dimention = " << n2.Dimension() << " " << n2 << "\n";

    n2 = n2 * 2;
    std::cout << "Dimention = " << n2.Dimension() << " " << n2 << "\n";
}
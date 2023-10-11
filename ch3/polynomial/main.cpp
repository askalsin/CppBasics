#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
class Polynomial {
public:
    using Container = typename std::vector<T>;
    using ConstIterator = typename Container::const_iterator;

private:
    Container coefficients;
    inline static const T valueTypeZero{0};

    void Normalize()
    {
        while (!coefficients.empty() && coefficients.back() == valueTypeZero) {
            coefficients.pop_back();
        }
    }

    Container& GetCoefficients()
    {
        return coefficients;
    }

public:
    Polynomial(const Container& coeffs) : coefficients{coeffs}
    {
        Normalize();
    }

    Polynomial(const T& value = {})
    {
        if (value != valueTypeZero) {
            coefficients.push_back(value);
        }
    }

    template <typename ForwardIt>
    Polynomial(ForwardIt first, ForwardIt last) : coefficients{first, last}
    {
        Normalize();
    }

    const Container& GetCoefficients() const
    {
        return coefficients;
    }

    friend bool operator==(const Polynomial<T>& lhs, const Polynomial<T>& rhs)
    {
        return lhs.GetCoefficients() == rhs.GetCoefficients();
    }

    friend bool operator!=(const Polynomial<T>& lhs, const Polynomial<T>& rhs)
    {
        return !(lhs == rhs);
    }

    Polynomial<T>& operator+=(const Polynomial<T>& other)
    {
        if (other.Degree() > Degree()) {
            GetCoefficients().resize(other.Degree() + 1);
        }

        for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
            GetCoefficients()[i] += other.GetCoefficients()[i];
        }
        Normalize();
        return *this;
    }

    Polynomial<T>& operator-=(const Polynomial<T>& other)
    {
        if (other.Degree() > Degree()) {
            GetCoefficients().resize(other.Degree() + 1);
        }

        for (int i = 0; i <= Degree() && i <= other.Degree(); ++i) {
            GetCoefficients()[i] -= other.GetCoefficients()[i];
        }
        Normalize();
        return *this;
    }

    Polynomial<T>& operator*=(const Polynomial<T>& other)
    {
        if (Degree() == -1 || other.Degree() == -1) {
            GetCoefficients().resize(0);
            return *this;
        }

        std::vector<T> tmp(Degree() + other.Degree() + 1);
        for (int i = 0; i <= Degree(); ++i) {
            for (int j = 0; j <= other.Degree(); ++j) {
                tmp[i + j] += GetCoefficients()[i] * other.GetCoefficients()[j];
            }
        }
        GetCoefficients() = std::move(tmp);
        Normalize();
        return *this;
    }

    friend Polynomial<T> operator+(Polynomial<T> lhs, const Polynomial<T>& rhs)
    {
        return lhs += rhs;
    }

    friend Polynomial<T> operator-(Polynomial<T> lhs, const Polynomial<T>& rhs)
    {
        return lhs -= rhs;
    }

    friend Polynomial<T> operator*(Polynomial<T> lhs, const Polynomial<T>& rhs)
    {
        return lhs *= rhs;
    }

    int Degree() const
    {
        return static_cast<int>(GetCoefficients().size()) - 1;
    }

    const T& operator[](size_t power) const
    {
        if (static_cast<int>(power) > Degree()) {
            return valueTypeZero;
        }
        return GetCoefficients()[power];
    }

    T operator()(const T& given_value) const
    {
        T result = valueTypeZero;

        for (auto i = Degree(); i >= 0; --i) {
            result *= given_value;
            result += GetCoefficients()[i];
        }

        return result;
    }

    ConstIterator begin() const
    {
        return GetCoefficients().cbegin();
    }

    ConstIterator end() const
    {
        return GetCoefficients().cend();
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Polynomial<T>& polynomial)
{
    for (auto i = polynomial.Degree(); i >= 0; --i) {
        out << polynomial[i];
        if (i != 0) {
            out << ' ';
        }
    }
    return out;
}

int main()
{
    Polynomial<int> n0;
    std::cout << n0 << "\n";
    std::vector<int> tmp = {1, 2, 3, 4, 5};

    Polynomial<int> n1(tmp);
    std::cout << n1 << "\n";

    Polynomial<int> n2(tmp.begin(), tmp.end());
    std::cout << n2 << "\n";

    auto first = n2.begin();
    auto last = n2.end();

    for (; first != last; ++first) {
        std::cout << *first << " ";
    }
    std::cout << "\n";

    bool is_equal = n1 == n2;
    std::cout << is_equal << "\n";

    bool is_not_equal = n1 != n2;
    std::cout << is_not_equal << "\n";

    tmp = {5};
    Polynomial<int> n3(tmp);
    std::cout << n3 << "\n";

    is_equal = n3 == 5;
    std::cout << is_equal << "\n";

    is_not_equal = n3 != 5;
    std::cout << is_not_equal << "\n";

    tmp = {1, 1, 1};
    Polynomial<int> n4(tmp);

    tmp = {0, 3, 2, 1};
    Polynomial<int> n5(tmp);

    auto n6 = n4 + n5;
    std::cout << n6 << "\n";
    n4 += n5;
    std::cout << n4 << "\n";
}
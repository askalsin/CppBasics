#include <iostream>
#include <numeric>

class Rational {
private:
    int numerator;
    int denomenator;

    void Reduce()
    {
        int gcd = std::gcd(numerator, denomenator);
        numerator /= gcd;
        denomenator /= gcd;
        if (denomenator < 0) {
            numerator = -numerator;
            denomenator = -denomenator;
        }
    }

public:
    Rational(int n = 0, int d = 1) : numerator(n), denomenator(d)
    {
        Reduce();
    }

    int Numerator() const
    {
        return numerator;
    }

    int Denominator() const
    {
        return denomenator;
    }

    Rational operator+() const
    {
        return {numerator, denomenator};
    }

    Rational operator-() const
    {
        return Rational(-numerator, denomenator);
    }

    Rational& operator+=(const Rational& rhs)
    {
        numerator = numerator * rhs.denomenator + rhs.numerator * denomenator;
        denomenator *= rhs.denomenator;
        Reduce();
        return *this;
    }

    Rational& operator-=(const Rational& rhs)
    {
        numerator = numerator * rhs.denomenator - rhs.numerator * denomenator;
        denomenator *= rhs.denomenator;
        Reduce();
        return *this;
    }

    Rational& operator*=(const Rational& rhs)
    {
        numerator *= rhs.numerator;
        denomenator *= rhs.denomenator;
        Reduce();
        return *this;
    }

    Rational& operator/=(const Rational& rhs)
    {
        int temp = rhs.numerator;
        numerator *= rhs.denomenator;
        denomenator *= temp;
        Reduce();
        return *this;
    }
};

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    Rational result = lhs;
    result += rhs;
    return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational result = lhs;
    result -= rhs;
    return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    Rational result = lhs;
    result *= rhs;
    return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational result = lhs;
    result /= rhs;
    return result;
}

bool operator==(const Rational& lhs, const Rational& rhs)
{
    return lhs.Numerator() == rhs.Numerator() &&
           lhs.Denominator() == rhs.Denominator();
}

bool operator!=(const Rational& lhs, const Rational& rhs)
{
    return !(lhs == rhs);
}

int main()
{
    Rational frac1(1, 2);
    Rational frac2(1, 3);

    frac1 += frac2;
    std::cout << frac1.Numerator() << "/" << frac1.Denominator() << "\n";

    frac1 -= frac2;
    std::cout << frac1.Numerator() << "/" << frac1.Denominator() << "\n";

    Rational frac3(3, 3);
    Rational frac4(9, 3);

    frac3 *= frac4;

    std::cout << frac3.Numerator() << "/" << frac3.Denominator() << "\n";

    Rational frac5(3, 2);
    Rational frac6(9, 3);

    frac6 *= frac5;

    std::cout << frac6.Numerator() << "/" << frac6.Denominator() << "\n";

    Rational frac7(1, 2);
    Rational frac8(1, 2);
    Rational frac9(1, 3);

    if (frac7 == frac8) {
        std::cout << "YES"
                  << "\n";
    }

    if (frac7 != frac9) {
        std::cout << "YES"
                  << "\n";
    }

    Rational frac10(1, 3);
    Rational frac11(1, 2);

    Rational frac12 = frac10 + frac11;

    std::cout << frac12.Numerator() << "/" << frac12.Denominator() << "\n";

    frac12 = 2 + frac10;

    std::cout << frac12.Numerator() << "/" << frac12.Denominator() << "\n";

    frac11 += 2;

    std::cout << frac11.Numerator() << "/" << frac11.Denominator() << "\n";
}
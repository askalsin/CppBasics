#include <iostream>

double CentimetersToInches(double centimeter)
{
    const double INCHE = 2.54;
    return centimeter / INCHE;
}

int main()
{
    double centimeter;
    std::cin >> centimeter;
    std::cout << CentimetersToInches(centimeter) << std::endl;
}

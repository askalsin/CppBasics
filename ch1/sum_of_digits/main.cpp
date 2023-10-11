#include <iostream>

int SumOfDigits(int num)
{
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << SumOfDigits(num) << std::endl;
}
#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

class TimerGuard {
private:
    std::string message;
    std::ostream& out;
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

public:
    TimerGuard(std::string message = "", std::ostream& out = std::cout)
        : message(message),
          out(out),
          start(std::chrono::high_resolution_clock::now())
    {
    }

    ~TimerGuard()
    {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        out << message << diff.count() << "\n";
    }
};

#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v = {9, 8, 7, 6, 5, 3, 2, 1};

    {
        TimerGuard timer("Sort elapsed: ", std::cout);
        std::sort(v.begin(), v.end());
    }

    return 0;
}
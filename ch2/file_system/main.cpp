#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> dirs;
    std::string path;

    while (std::getline(std::cin, path)) {
        for (size_t i = 0; i != path.size(); ++i) {
            if (path[i] == '/') {
                dirs.insert(path.substr(0, i + 1));
            }
        }
    }
    for (const auto& dir : dirs) {
        std::cout << dir << "\n";
    }
}
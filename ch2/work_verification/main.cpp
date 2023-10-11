#include <deque>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    size_t numberStudents;
    std::cin >> numberStudents;

    std::deque<std::string> students;
    std::string name, place;
    for (size_t i = 0; i != numberStudents; ++i) {
        std::cin >> name >> place;
        if (place == "top") {
            students.push_front(name);
        } else if (place == "bottom") {
            students.push_back(name);
        }
    }

    size_t numPapers;
    std::cin >> numPapers;

    std::vector<size_t> papers(numPapers);
    for (size_t& paper : papers) {
        std::cin >> paper;
    }

    for (const size_t& paper : papers) {
        std::cout << students[paper - 1] << std::endl;
    }
}
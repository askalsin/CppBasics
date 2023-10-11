#include <iostream>
#include <string>
#include <string_view>

bool NextToken(std::string_view& sv, const char delimiter,
               std::string_view& token)
{
    auto pos = sv.find(delimiter);
    if (pos != sv.npos) {
        token = sv.substr(0, pos);
        sv.remove_prefix(pos + 1);
        return true;
    }

    if (!sv.empty()) {
        token = sv;
        sv.remove_prefix(sv.size());
        return true;
    }

    return false;
}

int main()
{
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    // Делим строку на токены по разделителю и перебираем эти токены:
    while (NextToken(sv, delimiter, token)) {
        // обрабатываем очередной token
        // например, печатаем его на экране:
        std::cout << token << "\n";
    }
}
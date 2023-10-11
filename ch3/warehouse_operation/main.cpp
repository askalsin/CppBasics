#include <cstdint>
#include <list>
#include <set>
#include <unordered_map>

class Stock {
private:
    struct WeightNumber {
        int w;
        size_t i;

        bool operator<(const WeightNumber& other) const
        {
            if (w == other.w) {
                return i > other.i;
            }
            return w < other.w;
        }
    };

    struct VolumeNumber {
        int v;
        size_t i;

        bool operator<(const VolumeNumber& other) const
        {
            if (v == other.v) {
                return i > other.i;
            }
            return v < other.v;
        }
    };

    struct Iterators {
        std::set<WeightNumber>::iterator byW;
        std::set<VolumeNumber>::iterator byV;
    };

    std::list<Iterators> boxes;
    std::set<WeightNumber> sortedByW;
    std::set<VolumeNumber> sortedByV;
    std::unordered_map<size_t, std::list<Iterators>::iterator> indexes;
    size_t current_index{0};

public:
    void Add(int w, int v)
    {
        boxes.push_front({sortedByW.insert({w, current_index}).first,
                          sortedByV.insert({v, current_index}).first});
        indexes.insert({current_index, boxes.begin()});
        ++current_index;
    }

    int GetByW(int min_w)
    {
        const auto it = sortedByW.lower_bound({min_w, current_index});
        if (it == sortedByW.end()) {
            return -1;
        }

        size_t res = it->i;
        sortedByW.erase(it);
        sortedByV.erase(indexes[res]->byV);
        boxes.erase(indexes[res]);
        indexes.erase(res);
        return res;
    }

    int GetByV(int min_v)
    {
        const auto it = sortedByV.lower_bound({min_v, current_index});
        if (it == sortedByV.end()) {
            return -1;
        }

        size_t res = it->i;
        sortedByV.erase(it);
        sortedByW.erase(indexes[res]->byW);
        boxes.erase(indexes[res]);
        indexes.erase(res);
        return res;
    }
};

int main() {}
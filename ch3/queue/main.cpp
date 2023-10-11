#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Queue {
private:
    Container data;

public:
    Queue() {}

    T& front()
    {
        return data.front();
    }

    const T& front() const
    {
        return data.front();
    }

    void pop()
    {
        data.pop_front();
    }

    void push(const T& value)
    {
        data.push_back(value);
    }

    size_t size() const
    {
        return data.size();
    }

    bool empty() const
    {
        return data.empty();
    }

    bool operator==(const Queue& other) const
    {
        return data == other.data;
    }

    bool operator!=(const Queue& other) const
    {
        return !(data == other.data);
    }
};

int main() {}

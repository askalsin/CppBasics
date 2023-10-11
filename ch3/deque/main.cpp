#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

    void CheckIndex(size_t i)
    {
        if (i < 0 || i >= Size()) {
            throw std::out_of_range("incorrect index");
        }
    }

public:
    bool Empty() const
    {
        return head.empty() && tail.empty();
    }

    size_t Size() const
    {
        return head.size() + tail.size();
    }

    void Clear()
    {
        head.clear();
        tail.clear();
    }

    const T& operator[](size_t i) const
    {
        if (i < head.size()) {
            return head[head.size() - i - 1];
        }

        return tail[i - head.size()];
    }

    T& operator[](size_t i)
    {
        if (i < head.size()) {
            return head[head.size() - i - 1];
        }

        return tail[i - head.size()];
    }

    const T& At(size_t i) const
    {
        CheckIndex(i);
        return (*this)[i];
    }

    T& At(size_t i)
    {
        CheckIndex(i);
        return (*this)[i];
    }

    const T& Front() const
    {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    T& Front()
    {
        if (head.empty()) {
            return tail.front();
        }
        return head.back();
    }

    const T& Back() const
    {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    T& Back()
    {
        if (tail.empty()) {
            return head.front();
        }
        return tail.back();
    }

    void PushFront(const T& elem)
    {
        head.push_back(elem);
    }

    void PushBack(const T& elem)
    {
        tail.push_back(elem);
    }
};

int main()
{
    Deque<int> tmp;

    tmp.PushBack(1);
    tmp.PushBack(2);
    tmp.PushBack(3);
    tmp.PushFront(4);
    tmp.PushFront(5);
    tmp.PushFront(6);
    tmp.PushFront(7);
    tmp.PushFront(8);

    for (size_t i = 0; i < tmp.Size(); ++i) {
        std::cout << tmp[i] << " ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < tmp.Size(); ++i) {
        std::cout << tmp.At(i) << " ";
    }
    std::cout << "\n";

    std::cout << tmp.Back() << "\n";
    std::cout << tmp.Front() << "\n";

    tmp.At(100);
}
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
private:
    std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value)
    {
        data[key] = value;
    }

    void Remove(const Key& key)
    {
        data.erase(key);
    }

    bool Find(const Key& key, Value* const value = nullptr) const;
};

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* const value) const
{
    auto it = data.find(key);

    if (it != data.end() && value != nullptr) {
        *value = it->second;
    }

    return it != data.end();
}

int main()
{
    KeyValueStorage<std::string, int> kv;
    kv.Insert("hello", 42);
    kv.Insert("bye", -13);
    int value = 123;
    auto res = kv.Find("wrong", &value);
    // должно вернуться false, а value не должен меняться
    std::cout << "Res = " << res << " Value = " << value << "\n";
    res = kv.Find("bye", &value);
    // должно вернуться true, в value должно быть -13
    std::cout << "Res = " << res << " Value = " << value << "\n";
    res = kv.Find("hello", nullptr);
    // должно вернуться true
    std::cout << "Res = " << res << " Value = " << value << "\n";
}
#include <cstddef>
#include <iostream>
#include <string>

class Serializer {
public:
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string &) = 0;
    virtual void EndArray() = 0;
    virtual ~Serializer() {}
};

class JsonSerializer : public Serializer {
private:
    bool is_first = true;

    void check_first()
    {
        if (!is_first) {
            std::cout << ",";
        }
    }

public:
    void BeginArray() override
    {
        check_first();
        std::cout << "[";
        is_first = true;
    }

    void AddArrayItem(const std::string &item) override
    {
        check_first();
        std::cout << "\"" << item << "\"";
        is_first = false;
    }

    void EndArray() override
    {
        std::cout << "]";
        is_first = false;
    }
};

int main()
{
    JsonSerializer sr;
    sr.BeginArray();
    sr.BeginArray();
    sr.AddArrayItem("first");
    sr.AddArrayItem("second");
    sr.EndArray();
    sr.EndArray();
    sr.AddArrayItem("xxxx");
    sr.BeginArray();
    sr.AddArrayItem("first");
    sr.AddArrayItem("second");
    sr.EndArray();
    sr.BeginArray();
    sr.AddArrayItem("first");
    sr.AddArrayItem("second");
    sr.EndArray();
}
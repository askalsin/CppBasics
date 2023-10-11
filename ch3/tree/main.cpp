#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Node {
    std::map<std::string, Node> children;
};

class Tree {
private:
    Node root;

public:
    bool Has(const std::vector<std::string>& node) const;
    void Insert(const std::vector<std::string>& node);
    void Delete(const std::vector<std::string>& node);
};

bool Tree::Has(const std::vector<std::string>& node) const
{
    const Node* current = &root;
    for (const auto& item : node) {
        if (current->children.find(item) == current->children.end()) {
            return false;
        }
        current = &current->children.at(item);
    }
    return true;
}

void Tree::Insert(const std::vector<std::string>& node)
{
    Node* current = &root;
    for (const auto& item : node) {
        if (current->children.find(item) == current->children.end()) {
            current->children[item];
        }
        current = &current->children.at(item);
    }
}

void Tree::Delete(const std::vector<std::string>& node)
{
    Node* current = &root;
    for (size_t i = 0; i < node.size(); ++i) {
        const auto& item = node[i];
        if (current->children.find(item) == current->children.end()) {
            return;
        }
        if (i + 1 == node.size()) {
            current->children.erase(item);
        } else {
            current = &current->children.at(item);
        }
    }
}

int main() {}
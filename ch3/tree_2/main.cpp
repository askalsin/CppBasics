#include <iostream>
#include <memory>
#include <vector>

class TreeNode {
private:
    int value;
    TreeNode* root = nullptr;
    std::vector<std::unique_ptr<TreeNode>> children;

public:
    TreeNode(int val) : value(val) {}

    TreeNode(const TreeNode&) = delete;
    TreeNode& operator=(const TreeNode&) = delete;

    TreeNode* AddChild(int child_value)
    {
        children.push_back(std::make_unique<TreeNode>(child_value));
        children.back()->root = this;
        return children.back().get();
    }

    void Print(int depth = 0) const
    {
        for (int i = 0; i < depth; ++i) {
            std::cout << " ";
        }
        std::cout << "- " << value << "\n";
        for (const auto& child : children) {
            child->Print(depth + 1);
        }
    }
};

int main()
{
    TreeNode root(1);

    auto left_son = root.AddChild(10);
    auto middle_son = root.AddChild(20);
    auto right_son = root.AddChild(30);

    left_son->AddChild(100);
    left_son->AddChild(200);

    root.Print();
}
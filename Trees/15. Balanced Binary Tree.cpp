#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return dfs(root).first;
    }
    pair<int, int> dfs(TreeNode *node)
    {
        if (!node)
            return {1, 0};
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        if (!left.first || !right.first || abs(left.second - right.second) > 1)
            return {0, 0};
        return {1, 1 + max(left.second, right.second)};
    }
};
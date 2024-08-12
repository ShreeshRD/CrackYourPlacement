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
    int ans;
    int pathSum(TreeNode *root, int targetSum)
    {
        ans = 0;
        dfs(root, (long long)targetSum);
        return ans;
    }
    // Run test on every node
    void dfs(TreeNode *node, long long target)
    {
        if (!node)
            return;
        dfs(node->left, target);
        test(node, target);
        dfs(node->right, target);
    }
    void test(TreeNode *node, long long target)
    {
        if (!node)
            return;
        if (node->val == target)
            ans++;
        test(node->left, target - node->val);
        test(node->right, target - node->val);
    }
};
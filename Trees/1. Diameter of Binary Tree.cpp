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
    int diameterOfBinaryTree(TreeNode *root)
    {
        ans = 0;
        helper(root);
        return ans;
    }

private:
    int helper(TreeNode *node)
    {
        if (node == NULL)
            return -1;
        int lh = helper(node->left);
        int rh = helper(node->right);
        ans = max(ans, lh + rh + 2);
        return 1 + max(lh, rh);
    }
    int ans;
};
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    int ans;
    int maxPathSum(TreeNode *root)
    {
        ans = INT_MIN;
        int val = traverse(root);
        return max(ans, val);
    }
    int traverse(TreeNode *node)
    {
        int left = INT_MIN, right = INT_MIN, val = node->val;
        if (node->left)
            left = traverse(node->left);
        if (node->right)
            right = traverse(node->right);
        if (left > 0)
            val += left;
        if (right > 0)
            val += right;
        if (val < 0)
            ans = max(ans, max(left, right));
        else
            ans = max(ans, val);
        return node->val + max(0, max(left, right));
    }
};
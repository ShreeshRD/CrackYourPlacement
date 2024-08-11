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
    int ans = INT_MAX;
    TreeNode *prev = NULL;

    int getMinimumDifference(TreeNode *root)
    {
        if (!root)
            return ans;
        getMinimumDifference(root->left);
        if (prev)
            ans = min(ans, root->val - prev->val);
        prev = root;
        getMinimumDifference(root->right);
        return ans;
    }
};
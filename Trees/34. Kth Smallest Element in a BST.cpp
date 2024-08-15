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
    int count = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        if (!root)
            return 0;
        int left = kthSmallest(root->left, k);
        count++;
        if (k == count)
            return root->val;
        int right = kthSmallest(root->right, k);
        return max(left, right);
    }
};
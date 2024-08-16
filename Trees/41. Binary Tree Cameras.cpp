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
    int cams = 0;
    int minCameraCover(TreeNode *root)
    {
        return (dfs(root) == 0) ? cams + 1 : cams;
    }
    int dfs(TreeNode *node)
    {
        if (!node)
            return 1;
        int left = dfs(node->left);
        int right = dfs(node->right);
        if (left == 0 || right == 0)
        {
            cams++;
            return 2;
        }
        if (left == 2 || right == 2)
            return 1;
        return 0;
    }
};
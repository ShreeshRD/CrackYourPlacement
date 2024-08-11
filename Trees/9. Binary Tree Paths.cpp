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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string path;
        findPaths(root, ans, path);
        return ans;
    }
    void findPaths(TreeNode *node, vector<string> &ans, string path)
    {
        if (!node)
            return;
        path += to_string(node->val);
        if (!node->left && !node->right)
        {
            ans.push_back(path);
            return;
        }
        path += "->";
        findPaths(node->left, ans, path);
        findPaths(node->right, ans, path);
    }
};
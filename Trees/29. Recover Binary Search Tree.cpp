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
    TreeNode *prev = NULL, *left = NULL, *right;
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        swap(left->val, right->val);
    }
    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        if (prev && prev->val > node->val)
        {
            if (!left)
                left = prev;
            right = node;
        }
        prev = node;
        inorder(node->right);
    }
};
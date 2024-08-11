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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return symmetricHelper(root->left, root->right);
    }
    bool symmetricHelper(TreeNode *p, TreeNode *q)
    {
        if (p == NULL)
            return q == NULL;
        if (q == NULL)
            return false;
        if (p->val == q->val)
            return symmetricHelper(p->left, q->right) && symmetricHelper(p->right, q->left);
        return false;
    }
};
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ans = root;
        while (ans)
        {
            if (ans->val < p->val && ans->val < q->val)
                ans = ans->right;
            else if (ans->val > p->val && ans->val > q->val)
                ans = ans->left;
            else
                return ans;
        }
        return ans;
    }
};
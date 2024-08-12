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

class BSTIterator
{
public:
    stack<TreeNode *> mystack;
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    int next()
    {
        TreeNode *curr = mystack.top();
        mystack.pop();
        pushAll(curr->right);
        return curr->val;
    }

    bool hasNext()
    {
        return !mystack.empty();
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            mystack.push(node);
            node = node->left;
        }
    }
};
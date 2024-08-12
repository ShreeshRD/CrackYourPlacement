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
    int preIndex = 0, posIndex = 0;
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        TreeNode *head = new TreeNode(preorder[preIndex++]);
        if (head->val != postorder[posIndex])
            head->left = constructFromPrePost(preorder, postorder);
        if (head->val != postorder[posIndex])
            head->right = constructFromPrePost(preorder, postorder);
        posIndex++;
        return head;
    }
};
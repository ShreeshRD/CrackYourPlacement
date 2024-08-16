#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree of the tree which is also a BST
    tuple<int, int, int> dfs(Node *root)
    {
        if (!root)
            return make_tuple(0, INT_MAX, INT_MIN);

        int leftSize, leftMin, leftMax;
        tie(leftSize, leftMin, leftMax) = dfs(root->left);

        int rightSize, rightMin, rightMax;
        tie(rightSize, rightMin, rightMax) = dfs(root->right);

        if ((leftMax < root->data) && (root->data < rightMin))
            return make_tuple(leftSize + rightSize + 1, min(leftMin, root->data), max(rightMax, root->data));

        return make_tuple(max(leftSize, rightSize), INT_MIN, INT_MAX);
    }

    int largestBst(Node *root)
    {
        int ans, minVal, maxVal;
        tie(ans, minVal, maxVal) = dfs(root);
        return ans;
    }
};
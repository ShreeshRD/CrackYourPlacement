#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class Solution
{
public:
    int getCount(Node *root, int l, int h)
    {
        if (!root)
            return 0;
        if (root->data < l)
            return getCount(root->right, l, h);
        else if (root->data > h)
            return getCount(root->left, l, h);
        return 1 + getCount(root->right, l, h) + getCount(root->left, l, h);
    }
};
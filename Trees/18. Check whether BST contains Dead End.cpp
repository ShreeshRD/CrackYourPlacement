#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

class Solution
{
public:
    Node *prev = NULL;
    bool valid_leaf = false;
    bool isDeadEnd(Node *root)
    {
        if (!root)
            return false;
        bool flag1, flag2;
        flag1 = isDeadEnd(root->left);
        if (valid_leaf && root->data == prev->data + 1)
            return true;
        if (!root->left && !root->right)
        {
            int val = (prev ? prev->data : 0) + 1;
            if (val == root->data)
                valid_leaf = true;
            else
                valid_leaf = false;
        }
        else
            valid_leaf = false;
        prev = root;
        flag2 = isDeadEnd(root->right);
        return flag1 || flag2;
    }
};
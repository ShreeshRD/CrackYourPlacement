#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        if (!root)
            return;
        findPreSuc(root->left, pre, suc, key);
        if (root->key < key)
            pre = root;
        else if (root->key > key && !suc)
            suc = root;
        findPreSuc(root->right, pre, suc, key);
    }
};
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
    Node *bToDLL(Node *root)
    {
        if (!root->left && !root->right)
            return root;
        Node *head, *right = nullptr, *left = nullptr;
        if (root->left)
        {
            head = bToDLL(root->left);
            left = head;
            while (left->right)
                left = left->right;
            left->right = root;
        }
        else
            head = root;
        if (root->right)
        {
            right = bToDLL(root->right);
            right->left = root;
        }
        root->left = left;
        root->right = right;
        return head;
    }
};
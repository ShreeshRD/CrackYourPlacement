#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

class Solution
{
public:
    // Function that constructs BST from its preorder traversal.
    Node *Bst(int pre[], int size)
    {
        return constructBST(pre, 0, size - 1);
    }

private:
    // Helper function to construct BST from preorder traversal
    Node *constructBST(int pre[], int start, int end)
    {
        if (start > end)
            return nullptr;

        Node *root = newNode(pre[start]);

        // Find the first element greater than the root
        int i;
        for (i = start; i <= end; ++i)
        {
            if (pre[i] > root->data)
                break;
        }

        // Recursively construct the left and right subtrees
        root->left = constructBST(pre, start + 1, i - 1);
        root->right = constructBST(pre, i, end);

        return root;
    }
};
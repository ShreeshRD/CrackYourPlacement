#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

struct Node *construct(int n, int pre[], char preLN[], int &i)
{
    i++; // Increment the index
    if (i >= n)
        return nullptr; // Check if index is out of bounds

    if (preLN[i] == 'L')
        return new Node(pre[i]);

    Node *root = new Node(pre[i]);
    root->left = construct(n, pre, preLN, i);
    root->right = construct(n, pre, preLN, i);
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i = -1; // Initialize index to -1
    return construct(n, pre, preLN, i);
}
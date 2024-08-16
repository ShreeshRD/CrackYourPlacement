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

// your task is to complete the Function
// Function should return median of the BST
void inorderDFS(struct Node *node, vector<int> &arr)
{
    if (!node)
        return;
    inorderDFS(node->left, arr);
    arr.push_back(node->data);
    inorderDFS(node->right, arr);
}

float findMedian(struct Node *root)
{
    vector<int> arr;
    inorderDFS(root, arr);
    int n = arr.size();
    if (n % 2 == 1)
        return arr[n / 2];
    return (float)(arr[(n - 1) / 2] + arr[n / 2]) / 2;
}
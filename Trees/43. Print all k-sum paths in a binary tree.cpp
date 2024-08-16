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
    int count = 0;
    int sumK(Node *root, int k)
    {
        vector<int> path;
        findKPathUtil(root, path, k);
        return count;
    }

    void findKPathUtil(Node *root, vector<int> &path, int k)
    {
        if (!root)
            return;

        path.push_back(root->data);

        findKPathUtil(root->left, path, k);
        findKPathUtil(root->right, path, k);

        int f = 0;
        for (int j = path.size() - 1; j >= 0; j--)
        {
            f += path[j];

            if (f == k)
                count++;
        }

        path.pop_back();
    }
};
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
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int minDist = 0;
    int findDist(Node *root, int a, int b)
    {
        findMinDist(root, a, b);
        return minDist;
    }
    int findMinDist(Node *root, int a, int b)
    {
        if (!root)
            return 0;
        int left = findMinDist(root->left, a, b);
        int right = findMinDist(root->right, a, b);

        if (left && right)
        {
            minDist = left + right;
            return 0;
        }
        else if (root->data == a || root->data == b)
        {
            if (left || right)
            {
                minDist = max(left, right);
                return 0;
            }
            else
                return 1;
        }
        else if (left || right)
            return max(left, right) + 1;
        return 0;
    }
};
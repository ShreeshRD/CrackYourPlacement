#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<pair<int, int>, vector<TreeNode *>> dp;
    vector<TreeNode *> generateTrees(int n)
    {
        dp.clear();
        return generate(1, n);
    }
    vector<TreeNode *> generate(int left, int right)
    {
        if (left > right)
            return {NULL};
        if (dp.find({left, right}) != dp.end())
            return dp[{left, right}];
        vector<TreeNode *> res;
        for (int i = left; i <= right; i++)
        {
            for (auto leftTree : generate(left, i - 1))
            {
                for (auto rightTree : generate(i + 1, right))
                {
                    TreeNode *root = new TreeNode(i, leftTree, rightTree);
                    res.push_back(root);
                }
            }
        }
        dp[{left, right}] = res;
        return res;
    }
};
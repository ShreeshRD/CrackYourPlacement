#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, long long>> bfs;
        bfs.push({root, 0});
        long long ans = 0;
        while (!bfs.empty())
        {
            int qLen = bfs.size();
            long long leftMost = bfs.front().second, rightMost = bfs.back().second;
            ans = max(ans, (rightMost - leftMost + 1));
            for (int i = 0; i < qLen; i++)
            {
                auto temp = bfs.front();
                bfs.pop();
                long long idx = temp.second - leftMost;
                if (temp.first)
                {
                    if (temp.first->left)
                        bfs.push({temp.first->left, idx * 2});
                    if (temp.first->right)
                        bfs.push({temp.first->right, idx * 2 + 1});
                }
            }
        }
        return ans;
    }
};
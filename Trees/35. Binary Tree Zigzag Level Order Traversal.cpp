#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);
        bool order = false;
        while (!bfs.empty())
        {
            int qLen = bfs.size();
            order ^= true;
            vector<int> temp_arr;
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *curr = bfs.front();
                bfs.pop();
                if (curr)
                {
                    temp_arr.push_back(curr->val);
                    bfs.push(curr->left);
                    bfs.push(curr->right);
                }
            }
            if (!order)
                reverse(temp_arr.begin(), temp_arr.end());
            if (!temp_arr.empty())
                ans.push_back(temp_arr);
        }
        return ans;
    }
};
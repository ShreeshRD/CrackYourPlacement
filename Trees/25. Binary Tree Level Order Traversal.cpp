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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);

        while (!bfs.empty())
        {
            int qLen = bfs.size();
            vector<int> level;
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *temp = bfs.front();
                bfs.pop();
                if (temp)
                {
                    level.push_back(temp->val);
                    bfs.push(temp->left);
                    bfs.push(temp->right);
                }
            }
            if (!level.empty())
                ans.push_back(level);
        }

        return ans;
    }
};
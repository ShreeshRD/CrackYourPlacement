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
    map<int, vector<pair<int, int>>> grid;
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto ele : grid)
        {
            sort(ele.second.begin(), ele.second.end());
            vector<int> temp;
            for (auto pair : ele.second)
                temp.push_back(pair.second);
            ans.push_back(temp);
        }
        return ans;
    }
    void dfs(TreeNode *node, int row, int col)
    {
        if (!node)
            return;
        grid[col].push_back({row, node->val});
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
};
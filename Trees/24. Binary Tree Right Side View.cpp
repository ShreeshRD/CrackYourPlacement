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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);

        while (!bfs.empty())
        {
            TreeNode *rightSide = NULL;
            int qLen = bfs.size();
            for (int i = 0; i < qLen; i++)
            {
                TreeNode *temp = bfs.front();
                bfs.pop();
                if (temp)
                {
                    rightSide = temp;
                    bfs.push(temp->left);
                    bfs.push(temp->right);
                }
            }
            if (rightSide)
                ans.push_back(rightSide->val);
        }

        return ans;
    }
};
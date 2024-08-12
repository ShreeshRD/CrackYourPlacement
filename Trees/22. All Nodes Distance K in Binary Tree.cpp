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
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (k == 0)
            return {target->val};
        map<TreeNode *, vector<TreeNode *>> graph;
        queue<TreeNode *> process_me;
        process_me.push(root);
        while (!process_me.empty())
        {
            TreeNode *curr = process_me.front();
            process_me.pop();
            if (curr->left)
            {
                graph[curr].push_back(curr->left);
                graph[curr->left].push_back(curr);
                process_me.push(curr->left);
            }
            if (curr->right)
            {
                graph[curr].push_back(curr->right);
                graph[curr->right].push_back(curr);
                process_me.push(curr->right);
            }
        }
        vector<int> ans;
        set<TreeNode *> visited;
        visited.insert(target);
        queue<pair<TreeNode *, int>> bfs;
        bfs.push({target, 0});

        while (!bfs.empty())
        {
            auto ele = bfs.front();
            bfs.pop();
            if (ele.second == k)
                ans.push_back(ele.first->val);
            else
            {
                for (auto edge : graph[ele.first])
                {
                    if (visited.find(edge) == visited.end())
                    {
                        visited.insert(edge);
                        bfs.push({edge, ele.second + 1});
                    }
                }
            }
        }
        return ans;
    }
};
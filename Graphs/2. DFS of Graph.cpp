#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> ans;
        unordered_set<int> visited;

        dfs(0, adj, visited, ans);

        return ans;
    }

    void dfs(int node, vector<int> adj[], unordered_set<int> &visited, vector<int> &ans)
    {
        visited.insert(node);
        ans.push_back(node);

        for (int ele : adj[node])
        {
            if (visited.find(ele) == visited.end())
                dfs(ele, adj, visited, ans);
        }
    }
};
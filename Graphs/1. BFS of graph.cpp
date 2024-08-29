#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> bfs;
        unordered_set<int> visited;
        vector<int> ans;

        bfs.push(0);
        visited.insert(0);

        while (!bfs.empty())
        {
            int curr = bfs.front();
            ans.push_back(curr);
            bfs.pop();

            for (int ele : adj[curr])
            {
                if (visited.find(ele) == visited.end())
                {
                    bfs.push(ele);
                    visited.insert(ele);
                }
            }
        }

        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find minimum time required to rot all oranges.

    int orangesRotting(vector<vector<int>> &grid)
    {
        int time = 0, m = grid[0].size(), n = grid.size();
        bool change = true;
        // find all fresh fruits
        queue<pair<int, int>> fresh;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                    fresh.push({i, j});
        // process each phase
        while (change && !fresh.empty())
        {
            change = false;
            vector<vector<int>> copy = grid;
            queue<pair<int, int>> nextFresh;
            while (!fresh.empty())
            {
                bool proximity_rotten = false;
                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for (auto ele : directions)
                {
                    int new_i = fresh.front().first + ele.first, new_j = fresh.front().second + ele.second;
                    if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 2)
                    {
                        proximity_rotten = true;
                        break;
                    }
                }
                if (proximity_rotten)
                {
                    change = true;
                    copy[fresh.front().first][fresh.front().second] = 2;
                }
                else
                    nextFresh.push(fresh.front());
                fresh.pop();
            }
            grid = copy;
            fresh = nextFresh;
            time++;
        }
        if (fresh.size())
            return -1;
        return time;
    }
};
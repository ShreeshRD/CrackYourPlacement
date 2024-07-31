#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    count++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' || visited[i][j])
        {
            return;
        }
        visited[i][j] = true;
        // Explore all 8 directions
        dfs(grid, visited, i - 1, j);     // up
        dfs(grid, visited, i + 1, j);     // down
        dfs(grid, visited, i, j - 1);     // left
        dfs(grid, visited, i, j + 1);     // right
        dfs(grid, visited, i - 1, j - 1); // up-left
        dfs(grid, visited, i - 1, j + 1); // up-right
        dfs(grid, visited, i + 1, j - 1); // down-left
        dfs(grid, visited, i + 1, j + 1); // down-right
    }
};
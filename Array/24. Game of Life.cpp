#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        vector<vector<int>> prev;
        prev = board;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                for (int x = -1; x < 2; x++)
                {
                    for (int y = -1; y < 2; y++)
                    {
                        int nx = j + x, ny = i + y;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                            continue;
                        if (x == 0 && y == 0)
                            continue;
                        if (prev[ny][nx] == 1)
                            count++;
                    }
                }
                if (count < 2 || count > 3)
                    board[i][j] = 0;
                else if (prev[i][j] == 0 && count == 2)
                    board[i][j] = 0;
                else
                    board[i][j] = 1;
            }
        }
    }
};
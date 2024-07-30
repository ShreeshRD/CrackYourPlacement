#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Replace all O's with -
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O')
                    mat[i][j] = '-';
            }
        }

        // Top and bottom rows
        for (int j = 0; j < m; j++)
        {
            if (mat[0][j] == '-')
                floodFillUtil(mat, 0, j, '-', 'O');
            if (mat[n - 1][j] == '-')
                floodFillUtil(mat, n - 1, j, '-', 'O');
        }

        // Left and Right columns
        for (int i = 0; i < n; i++)
        {
            if (mat[i][0] == '-')
                floodFillUtil(mat, i, 0, '-', 'O');
            if (mat[i][m - 1] == '-')
                floodFillUtil(mat, i, m - 1, '-', 'O');
        }

        // Replace all '-' with 'X'
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (mat[i][j] == '-')
                    mat[i][j] = 'X';

        return mat;
    }

    void floodFillUtil(vector<vector<char>> &screen, int x, int y, char prevColor, char newColor)
    {
        int rows = screen.size();
        int cols = screen[0].size();

        // Base cases
        if (x < 0 || x >= rows || y < 0 || y >= cols)
            return;
        if (screen[x][y] != prevColor)
            return;
        if (screen[x][y] == newColor)
            return;

        // Replace the color at (x, y)
        screen[x][y] = newColor;

        // Recur for north, east, south, and west
        floodFillUtil(screen, x + 1, y, prevColor, newColor);
        floodFillUtil(screen, x - 1, y, prevColor, newColor);
        floodFillUtil(screen, x, y + 1, prevColor, newColor);
        floodFillUtil(screen, x, y - 1, prevColor, newColor);
    }
};
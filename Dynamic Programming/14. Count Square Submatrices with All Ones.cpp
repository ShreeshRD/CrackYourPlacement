#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < n; i++)
            ans += matrix[0][i];
        for (int i = 1; i < m; i++)
            ans += matrix[i][0];
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != 0)
                {
                    matrix[i][j] = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                    ans += matrix[i][j];
                }
            }
        }
        return ans;
    }
};
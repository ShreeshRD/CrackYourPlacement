#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size() - 1;
        int n = matrix[0].size();
        int r = 0, c = -1;
        int cdir = 1, rdir = 1;
        vector<int> ans;
        while (n > 0)
        {
            for (int j = 1; j <= n; j++)
                ans.push_back(matrix[r][c + j * cdir]);
            c += cdir * n;
            n -= 1;
            cdir *= -1;
            if (m == 0)
                break;
            for (int i = 1; i <= m; i++)
                ans.push_back(matrix[r + i * rdir][c]);
            r += rdir * m;
            m -= 1;
            rdir *= -1;
        }
        return ans;
    }
};
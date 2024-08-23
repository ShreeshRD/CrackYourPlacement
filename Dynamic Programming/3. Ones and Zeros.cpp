#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int zeros, int ones)
    {
        int i, j, k, l, p = strs.size();
        vector<vector<int>> dp(zeros + 1, vector<int>(ones + 1));

        for (auto &s : strs)
        {
            int currOnes = count(s.begin(), s.end(), '1');
            int currZeros = s.size() - currOnes;

            for (j = ones; j >= currOnes; j--)
            {
                for (i = zeros; i >= currZeros; i--)
                {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - currZeros][j - currOnes]);
                }
            }
        }
        return dp[zeros][ones];
    }
};
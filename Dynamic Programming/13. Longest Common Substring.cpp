#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string str1, string str2)
    {
        int m = str1.size(), n = str2.size(), max_len = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > max_len)
                    {
                        max_len = dp[i][j];
                    }
                }
            }
        }
        return max_len;
    }
};
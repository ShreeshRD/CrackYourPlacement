#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> dp(n + 1);
        if (x <= n)
            dp[x] = 1;
        if (y <= n)
            dp[y] = 1;
        if (z <= n)
            dp[z] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i >= x && dp[i - x])
                dp[i] = max(dp[i], 1 + dp[i - x]);
            if (i >= y && dp[i - y])
                dp[i] = max(dp[i], 1 + dp[i - y]);
            if (i >= z && dp[i - z])
                dp[i] = max(dp[i], 1 + dp[i - z]);
        }
        return dp[n];
    }
};
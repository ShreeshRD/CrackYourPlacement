#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp = {0};
        for (int i = 1; i <= n; i++)
            dp.push_back(i % 2 + dp[i / 2]);
        return dp;
    }
};
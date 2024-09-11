#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getCount(int n)
    {
        unordered_map<int, vector<int>> keypad_map = {
            {1, {1, 2, 4}},
            {2, {1, 2, 3, 5}},
            {3, {2, 3, 6}},
            {4, {1, 4, 5, 7}},
            {5, {2, 4, 5, 6, 8}},
            {6, {3, 5, 6, 9}},
            {7, {4, 7, 8}},
            {8, {5, 7, 8, 9, 0}},
            {9, {6, 8, 9}},
            {0, {0, 8}}};
        vector<vector<long long>> dp(2, vector<long long>(10, 1));
        long long ans = 0;
        for (int i = 1; i < n; i++)
        {
            for (auto pair : keypad_map)
            {
                dp[1][pair.first] = 0;
                for (auto ele : pair.second)
                    dp[1][pair.first] += dp[0][ele];
            }
            dp[0] = dp[1];
        }
        for (auto ele : dp[0])
            ans += ele;
        return ans;
    }
};
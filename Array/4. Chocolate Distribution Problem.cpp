#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int l = 0, r = 0;
        int profit = 0;
        while (r < n)
        {
            if (prices[r] < prices[l])
                l = r;
            profit = max(profit, prices[r] - prices[l]);
            r++;
        }
        return profit;
    }
};
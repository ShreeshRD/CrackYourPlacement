#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size(), lsize = 0;
        vector<int> lis;
        for (int i = 0; i < n; i++)
        {
            int lb = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            if (lb == lsize)
            {
                lis.push_back(nums[i]);
                lsize++;
            }
            else
                lis[lb] = nums[i];
        }
        return lsize;
    }
};
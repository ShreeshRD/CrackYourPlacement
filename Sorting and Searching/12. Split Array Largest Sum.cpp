#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size(), ans;
        long long l = *max_element(nums.begin(), nums.end()), r = accumulate(nums.begin(), nums.end(), 0LL);
        while (l <= r)
        {
            long long mid = l + (r - l) / 2;
            int parts = 1, part_sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (part_sum + nums[i] > mid)
                {
                    parts++;
                    part_sum = 0;
                }
                part_sum += nums[i];
            }
            if (parts <= k)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
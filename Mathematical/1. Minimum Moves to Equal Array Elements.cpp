#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        int ans = 0;
        while (l < r)
        {
            ans += nums[r] - nums[l];
            l++;
            r--;
        }
        return ans;
    }
};
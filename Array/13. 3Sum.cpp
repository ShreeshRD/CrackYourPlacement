#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> sol;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                break;
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int r_sum = nums[i] * (-1), l = i + 1, r = n - 1;
            while (l < r)
            {
                if (nums[l] + nums[r] < r_sum)
                    l++;
                else if (nums[l] + nums[r] > r_sum)
                    r--;
                else
                {
                    sol.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while (nums[l] == nums[l - 1] && l < r)
                        l++;
                }
            }
        }
        return sol;
    }
};
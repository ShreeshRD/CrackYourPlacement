#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n - 3; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1;
                int r = n - 1;
                long long req = (long long)target - nums[i] - nums[j];
                while (l < r)
                {
                    if (nums[l] + nums[r] < req)
                        l++;
                    else if (nums[l] + nums[r] > req)
                        r--;
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        while (l < r && nums[l] == nums[l - 1])
                            l++;
                    }
                }
            }
        }
        return ans;
    }
};
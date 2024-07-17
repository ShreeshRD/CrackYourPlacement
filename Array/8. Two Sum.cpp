#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int comp;
        for (int i = 0; i < nums.size(); i++)
        {
            comp = target - nums[i];
            if (mp.count(comp))
            {
                return {mp[comp], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
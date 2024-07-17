#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        for (int num : nums)
        {
            if (nums[abs(num) - 1] < 0)
                ans.push_back(abs(num));
            nums[abs(num) - 1] *= -1;
        }
        return ans;
    }
};
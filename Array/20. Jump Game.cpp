#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int max_index = 0, pos = 0, n = nums.size();
        while (pos <= max_index)
        {
            max_index = max(max_index, pos + nums[pos]);
            pos++;
            if (max_index >= n - 1)
                return true;
        }
        return false;
    }
};
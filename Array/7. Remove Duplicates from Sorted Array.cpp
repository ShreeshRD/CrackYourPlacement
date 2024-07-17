#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int uniq_pos = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[uniq_pos] = nums[i];
                uniq_pos++;
            }
        }
        return uniq_pos;
    }
};
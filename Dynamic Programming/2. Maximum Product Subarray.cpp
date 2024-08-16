#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        double r = nums[0];
        double imax = r, imin = r;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(imax, imin);
            imax = max((double)nums[i], imax * nums[i]);
            imin = min((double)nums[i], imin * nums[i]);

            r = max(r, imax);
        }
        return (int)r;
    }
};
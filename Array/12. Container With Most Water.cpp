#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0;
        int r = height.size() - 1;
        int max_vol = -1;
        while (l < r)
        {
            int cur_vol = min(height[l], height[r]) * (r - l);
            max_vol = max(max_vol, cur_vol);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return max_vol;
    }
};
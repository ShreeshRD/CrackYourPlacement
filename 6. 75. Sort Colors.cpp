#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int snowballSize = 0;
        int n = nums.size();
        // Push 1s to the end
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                snowballSize++;
            else if (snowballSize != 0)
            {
                int t = nums[i];
                nums[i] = 1;
                nums[i - snowballSize] = t;
            }
        }
        // Push 2s to the end
        snowballSize = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
                snowballSize++;
            else if (snowballSize != 0)
            {
                int t = nums[i];
                nums[i] = 2;
                nums[i - snowballSize] = t;
            }
        }
    }
};
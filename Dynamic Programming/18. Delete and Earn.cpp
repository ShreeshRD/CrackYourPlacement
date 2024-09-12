#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        unordered_map<int, int> count;
        for (int num : nums)
            count[num]++;

        set<int> s(nums.begin(), nums.end());

        int prev1 = 0, prev2 = 0, curr = 0;
        int prevNum = -1;

        for (int num : s)
        {
            curr = num * count[num];
            int temp = prev2;
            if (num == prevNum + 1)
                prev2 = max(curr + prev1, prev2);
            else
                prev2 = curr + prev2;
            prev1 = temp;
            prevNum = num;
        }
        return prev2;
    }
};
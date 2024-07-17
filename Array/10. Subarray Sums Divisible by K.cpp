#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        vector<int> map(k);
        map[0] = 1;
        int count = 0, sum = 0;
        for (int num : nums)
        {
            sum += num;
            sum %= k;
            if (sum < 0)
                sum += k;
            count += map[sum];
            map[sum]++;
        }
        return count;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        map<int, int> pre;
        pre[0] = 1;
        int csum = 0;
        int ans = 0;
        for (int num : nums)
        {
            csum += num;
            int needed = csum - k;
            ans += pre[needed];
            pre[csum]++;
        }
        return ans;
    }
};
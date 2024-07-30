#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        vector<long long int> ans(n, 1);
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];
        long long int rprod = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] *= rprod;
            rprod *= nums[i];
        }
        return ans;
    }
};
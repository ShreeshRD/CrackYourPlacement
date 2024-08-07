#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> nums1Idx;
        for (int i = 0; i < nums1.size(); i++)
            nums1Idx[nums1[i]] = i + 1;
        vector<int> res(nums1.size(), -1);
        stack<int> mystack;
        for (auto num : nums2)
        {
            while (!mystack.empty() && num > mystack.top())
            {
                res[nums1Idx[mystack.top()] - 1] = num;
                mystack.pop();
            }
            if (nums1Idx[num] > 0)
                mystack.push(num);
        }
        return res;
    }
};
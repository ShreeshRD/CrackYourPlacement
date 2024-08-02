#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[r] < nums[mid])
                l = mid + 1;
            else
                r = mid;
        }
        int pivot = l;
        cout << pivot << endl;
        l = 0;
        r = n - 1;
        if (target == nums[pivot])
            return pivot;
        if (target <= nums[n - 1])
            l = pivot;
        else
            r = pivot - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};
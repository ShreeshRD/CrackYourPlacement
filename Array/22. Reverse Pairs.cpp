#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> temp(nums.size());
        return mergeSortAndCount(nums, temp, 0, nums.size() - 1);
    }

private:
    int mergeSortAndCount(vector<int> &nums, vector<int> &temp, int left, int right)
    {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;
        int count = mergeSortAndCount(nums, temp, left, mid) + mergeSortAndCount(nums, temp, mid + 1, right);

        // Count reverse pairs
        int j = mid + 1;
        for (int i = left; i <= mid; ++i)
        {
            while (j <= right && nums[i] > 2LL * nums[j])
            {
                ++j;
            }
            count += (j - (mid + 1));
        }

        // Merge the two sorted halves
        merge(nums, temp, left, mid, right);

        return count;
    }

    void merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right)
    {
        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = nums[i++];
        }

        while (j <= right)
        {
            temp[k++] = nums[j++];
        }

        for (i = left; i <= right; ++i)
        {
            nums[i] = temp[i];
        }
    }
};
#include <bits/stdc++.h>
using namespace std;

class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        if (n > 0)
        {
            // The size of the segment tree array is 4 * n
            segmentTree.resize(4 * n);
            // Build the segment tree
            buildSegmentTree(nums, 0, 0, n - 1);
        }
    }

    int sumRange(int left, int right)
    {
        // Query the segment tree for the sum in the range [left, right]
        return querySegmentTree(0, 0, n - 1, left, right);
    }

private:
    vector<int> segmentTree;
    int n;

    // Helper function to build the segment tree
    void buildSegmentTree(vector<int> &nums, int treeIndex, int l, int r)
    {
        // Base case: leaf node
        if (l == r)
        {
            segmentTree[treeIndex] = nums[l];
            return;
        }

        // Recursive case: internal node
        int mid = l + (r - l) / 2;                             // Corrected calculation of mid
        buildSegmentTree(nums, 2 * treeIndex + 1, l, mid);     // Left child
        buildSegmentTree(nums, 2 * treeIndex + 2, mid + 1, r); // Right child

        // Combine the results from left and right children
        segmentTree[treeIndex] = segmentTree[2 * treeIndex + 1] + segmentTree[2 * treeIndex + 2];
    }

    // Helper function to query the segment tree
    int querySegmentTree(int treeIndex, int l, int r, int left, int right)
    {
        // Total overlap
        if (left <= l && right >= r)
            return segmentTree[treeIndex];
        // No overlap
        if (right < l || left > r)
            return 0;
        // Partial overlap
        int mid = l + (r - l) / 2;
        return querySegmentTree(treeIndex * 2 + 1, l, mid, left, right) +
               querySegmentTree(treeIndex * 2 + 2, mid + 1, r, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
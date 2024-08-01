#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPair(int n, int x, vector<int> &arr)
    {
        int l = 0, r = 1;
        sort(arr.begin(), arr.end());
        while (r < n)
        {
            int diff = arr[r] - arr[l];
            if (diff == x)
                return 1;
            else if (diff < x)
                r++;
            else
                l++;
            if (l == r)
                r++;
        }
        return -1;
    }
};